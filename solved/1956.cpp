#include <cstdio>
#include <algorithm>
using namespace std;
int adj[401][401] = { 0 };
const int INF = 987654321;
int main(){
    int v,e; scanf("%d%d",&v,&e);
    for( int i = 1 ; i <= v ; ++i ){
        for( int j = 1 ; j <= v; ++j ){
            if( i == j ) continue;
            adj[i][j] = INF;
        }
    }
    
    for( int i = 0 ; i < e ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a][b] = c;
    }
    int ret = INF;
    for( int k = 1 ; k <= v ; ++k ){
        for( int i = 1 ; i <= v ; ++i ){
            if( adj[i][k] >= INF ) continue;
            for( int j = 1 ; j <= v ; ++j ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    for( int i = 1 ; i <= v ; ++i ){
        for( int j = 1 ; j <= v ; ++j ){
            if( i == j ) continue;
            if( adj[i][j] >= INF ) continue;
            if( adj[j][i] >= INF ) continue;
            ret = min(ret, adj[i][j]+adj[j][i]);
        }
    }
    if( ret >= INF ) ret = -1;
    printf("%d",ret);
    return 0;
}