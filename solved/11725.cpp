#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int par[100001] = { 0 };
vector<int> adj[100001];
int n;
int main(){
    scanf("%d",&n);
    for ( int i = 0 ; i < n-1 ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    bool visited[100001] = { false };
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for( auto next : adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                par[next] = cur;
                q.push(next);
            }
        }
    }
    for( int i = 2 ; i <= n ; ++i ){
        printf("%d\n", par[i]);
    }
    return 0;
}