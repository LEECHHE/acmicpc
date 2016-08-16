#include <iostream>
#include <cstring>
using namespace std;
int cost[1005][1005];
bool visited[1005];
int n,m;
int min(int& a, int& b) { return a < b ? a : b; }
int solve(int v, int cst){
    visited[v] = true;
    
    int ret = 0;
    bool hasOne = true;
    for( int i = 2 ; i <= n ; ++i ){
        if( cost[v][i] && !visited[i] ){
            hasOne = false;
            ret += solve(i, cost[v][i]);
        }
    }
    return hasOne? cst : min(ret,cst);
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        memset(cost,0,sizeof(cost));
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&n,&m);
        for( int i = 0 ; i < m ; ++i ){
            int a,b,d; scanf("%d%d%d",&a,&b,&d);
            cost[b][a] = cost[a][b] = d;
        }
        int ret = 0;
        visited[1] = true;
        for( int i = 2 ; i <= n ; ++i ){
            if( cost[1][i] ) ret += solve(i, cost[1][i]);
        }
        printf("%d\n",ret);
    }
    return 0;
}