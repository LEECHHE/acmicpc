#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[1000001];
int degree[1000001];
int dp[1000001][2];
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n-1 ; ++i ){
        int a,b; scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    for( int i = 1 ; i <= n ; ++i ){
        dp[i][1] = 1;
        degree[i] = (int)adj[i].size();
    }
    int root = -1;
    for( int i = 1 ; i <= n ; ++i ){
        if( degree[i] == 1 ){
            q.push(i);
            root = i;
        }
    }
    bool visited[1000001] = { false };
    while (!q.empty()) {
        int now = q.front(); q.pop();
        visited[now] = true;
        for( auto next : adj[now] ){
            if( visited[next] ) continue;
            dp[next][0] += dp[now][1];
            dp[next][1] += min(dp[now][0], dp[now][1]);
            if( --degree[next] == 1 ){
                q.push(next);
                root = next;
            }
        }
    }
    printf("%d", min(dp[root][0], dp[root][1]));
    return 0;
}