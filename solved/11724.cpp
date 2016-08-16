#include <cstdio>
using namespace std;
bool visited[1001] = { false };
bool adj[1001][1001] = { false };
int n,m;
void dfs(int cur){
    for( int i = 1 ; i <= n ; ++i ){
        if( adj[cur][i] && !visited[i] ){
            visited[i] = true;
            dfs(i);
        }
    }
}
int main(){
    
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if(!visited[i]){
            ++ret;
            dfs(i);
        }
    }
    printf("%d",ret);
    return 0;
}