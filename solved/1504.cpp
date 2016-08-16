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
int adj[800][800] = { 0 };
int node[2][800];
int n,e;
const int INF = (1<<31)-1;
void dijkstra(int start, int idx){
    for( int i = 0 ; i < n ; ++i ){
        node[idx][i] = INF;
    }
    
    queue<int> q;
    q.push(start);
    node[idx][start] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for( int next = 0 ; next < n ; ++next ){
            if( adj[cur][next] != INF && node[idx][next] > node[idx][cur] + adj[cur][next] ){
                node[idx][next] = node[idx][cur] + adj[cur][next];
                q.push(next);
            }
        }
    }
}
int main(){
    scanf("%d%d", &n,&e);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < e ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a-1][b-1] = adj[b-1][a-1] = c;
    }
    int distinct[2]; scanf("%d%d", &distinct[0], &distinct[1]);
    --distinct[0]; --distinct[1];
    
    dijkstra(distinct[0], 0);
    dijkstra(distinct[1], 1);
    int distance[2] = { INF, INF };
    if( node[0][0] != INF && node[0][distinct[1]] != INF && node[1][n-1] != INF ){
        distance[0] = node[0][0] + node[0][distinct[1]] + node[1][n-1];
    }
    if( node[1][0] != INF && node[1][distinct[0]] != INF && node[0][n-1] != INF ){
        distance[1]= node[1][0] + node[1][distinct[0]] + node[0][n-1];
    }
    int ret = min( distance[0], distance[1] );
    if( ret >= INF ) ret = -1;
    printf("%d\n", ret);
    return 0;
}