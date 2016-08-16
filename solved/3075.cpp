#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    const int INF = 987654321;
    while (t--) {
        int n,p,q; scanf("%d%d%d",&n,&p,&q);
        int part[100];
        for(int i = 0 ; i < n ; i += scanf("%d",&part[i]));
        int adj[101][101] = { 0 };
        for( int i = 1 ; i <= p ; ++i ){
            for( int j = 1 ; j <= p ; ++j ){
                if(i == j ) continue;
                adj[i][j] = INF;
            }
        }
        for( int i = 0 ; i < q ; ++i ){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adj[a][b] = adj[b][a] = c;
        }
        for( int k = 1 ; k <= p ; ++k ){
            for( int i = 1 ; i <= p ; ++i ){
                if( adj[i][k] >= INF ) continue;
                for( int j = 1 ; j <= p ; ++j ){
                    if( i == j || adj[k][j] >= INF ) continue;
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int num = 0, cost = INF;
        for( int i = 1 ; i <= p ; ++i ){
            int cur = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( adj[part[j]][i] >= INF ){
                    cur = INF;
                    break;
                }
                cur += adj[part[j]][i]*adj[part[j]][i];
            }
            if( cur < cost ){
                num = i;
                cost = cur;
            }
        }
        printf("%d %d\n", num, cost);
    }
    return 0;
}