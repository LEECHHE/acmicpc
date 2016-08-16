#include <cstdio>
#include <algorithm>
using namespace std;
int adj[101][101];
const int INF = 987654321;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            if( i == j ) continue;
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = 1;
    }
    
    for( int k = 1 ; k <= n ; ++k ){
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= n ; ++j ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        int cnt = n;
        for( int j = 1 ; j <= n ; ++j ){
            cnt -= (adj[i][j] < INF || adj[j][i] < INF);
        }
        printf("%d\n", cnt);
    }
    return 0;
}