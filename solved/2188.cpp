#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int adj[201][201] = { 0 };
bool visited[201] = { false };
int match[201];
bool bpm( int v ){
    if( visited[v] ) return false;
    visited[v] = true;
    for( int b = 1 ; b <= m ; ++b ){
        if( !adj[v][b] ) continue;
        if( match[b] == -1 || bpm(match[b])){
            match[b] = v;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for( int i = 1 ; i <= n ; ++i ){
        int k; scanf("%d", &k);
        for( int j = 0 ; j < k ; ++j ){
            int b; scanf("%d",&b);
            adj[i][b] = 1;
        }
    }
    int ret = 0;
    for( int i = 1 ; i <= m ; ++i ) match[i] = -1;
    for( int start = 1 ; start <= n ; ++start ){
        memset(visited, 0, sizeof(visited));
        if( bpm(start) ) ++ret;
    }
    printf("%d", ret);
    return 0;
}