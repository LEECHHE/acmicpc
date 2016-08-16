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
int n,m;
const int INF = (1<<31)-1;
vector<vector<bool>> adj;
vector<int> combination;
//vector<bool> visited;
void dfs(int& cnt, int curNode, int step){
    if( step == 0 ){
        ++cnt;
        return;
    }
    combination.push_back(curNode);
    for ( int i = curNode+1 ; i <= n ; ++i ){
        bool success = true;
        for ( auto node : combination ){
            if( !adj[node][i] ){
                success = false;
                break;
            }
        }
        if( success ){
            dfs(cnt, i, step-1);
        }
    }
    combination.erase(combination.end()-1);
}
int main(){
    scanf("%d%d",&n,&m);
    adj = vector<vector<bool>>(n+1, vector<bool>(n+1,true));
//    visited = vector<bool>(n+1, false);
    for( int i = 0 ; i <= n ; ++i ) adj[i][i] = false;
    for( int i = 1 ; i <= m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = adj[b][a] = false;
    }
    int ret = 0;
    for( int i = 1 ; i <= n-2 ; ++i ){
        combination.clear();
        dfs(ret, i, 2);
    }
    printf("%d", ret);
    return 0;
}