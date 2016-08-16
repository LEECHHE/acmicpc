#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int adj[101][101];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 0 ; i <= n ; ++i ){
        for( int j = 0 ; j <= n ; ++j ){
            if( i == j ) continue;
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a][b] = min(adj[a][b], c);
    }
    
    for( int k = 1 ; k <= n ; ++k ){
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= n ; ++j ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}