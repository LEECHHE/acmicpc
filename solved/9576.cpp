#include <cstdio>
#include <cstring>
using namespace std;
bool visited[1001] = { false };
bool adj[1001][1001] = { false };
int match[1001] = { 0 };
int n,m;
bool bpm(int v){
    if(visited[v]) return false;
    visited[v] = true;
    for( int book = 1 ; book <= n ;++book){
        if (!adj[v][book]) continue;
        if ( match[book] == 0 || bpm(match[book]) ) {
            match[book] = v;
            return true;
        }
    }
    return false;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        memset(adj, 0, sizeof(adj));
        memset(match, 0, sizeof(match));
        scanf("%d%d",&n,&m);
        for( int i = 1 ; i <= m ; ++i ){
            int a,b; scanf("%d%d",&a,&b);
            for( int book = a ; book <= b ; ++book ){
                adj[i][book] = true;
            }
        }
        int ret = 0;
        for( int i = 1 ; i <= m ; ++i ){
            memset(visited, 0, sizeof(visited));
            if( bpm(i) ){
                ++ret;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}