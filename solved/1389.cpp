#include <cstdio>
#include <algorithm>
using namespace std;
int adj[101][101];
const int INF = 987654321;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    for( int k = 1 ; k <= n ; ++k ){
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= n ; ++j ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int ret = 0;
    int min = INF;
    for( int i = 1 ; i <= n ; ++i ){
        int sum = 0;
        for( int j = 1 ; j <= n ; ++j ){
            if( adj[i][j] < INF ){
                sum += adj[i][j];
            }
        }
        if( min > sum ){
            ret = i;
            min = sum;
        }
    }
    printf("%d",ret);
    return 0;
}