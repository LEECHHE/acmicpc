#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int adj[101][5001] = { 0 };
bool visited[101] = { false };
int match[5001];
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
    for( int i = 0 ; i < m ; ++i ){
        int x,y; scanf("%d%d",&x,&y);
        adj[x][y] = 1;
    }
    int ret = 0;
    memset(match, -1, sizeof(match));
    for( int start = 1 ; start <= n ; ++start ){
        memset(visited, 0, sizeof(visited));
        if( bpm(start) ) ++ret;
    }
    printf("%d", ret);
    return 0;
}