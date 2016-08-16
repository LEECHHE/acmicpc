#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
vector<int> adj[1001];
vector<int> dag;
bool success;
bool visited[1001] = { false };
bool finished[1001] = { false };
int n, m;
void dfs(int cur){
    if( !success ) return;
    visited[cur] = true;
    for( auto next : adj[cur] ){
        if( !visited[next] ){
            dfs(next);
        }
        else if( !finished[next] ){
            success = false;
            return;
        }
    }
    dag.push_back(cur);
    finished[cur] = true;
}
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int k; scanf("%d",&k);
        int cur; scanf("%d",&cur);
        adj[0].push_back(cur);
        for( int i = 1 ; i < k ; ++i ){
            int next; scanf("%d", &next);
            adj[cur].push_back(next);
            cur = next;
        }
    }
    success = true;
    dfs(0);
    dag.pop_back();
    for( int i = 1 ; i <= n ; ++i ){
        if( !visited[i])
            dfs(i);
    }
    if( !success ){
        printf("0");
    }
    else{
        reverse(dag.begin(), dag.end());
        for( auto node : dag ){
            printf("%d\n", node);
        }
    }
    return 0;
}