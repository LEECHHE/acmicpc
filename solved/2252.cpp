#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[32001];
bool notRoot[32001] = { false };
bool visited[32001] = { false };
vector<int> ret;
void dfs(int v){
    for (auto next : adj[v] ){
        if( !visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
    printf("%d ",v);
}
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[b].push_back(a);
        notRoot[a] = true;
    }
    for( int i = 1 ; i <= n ; ++i ){
        if(!visited[i] && !notRoot[i] ){
            visited[i] = true;
            dfs(i);
        }
    }
    return 0;
}