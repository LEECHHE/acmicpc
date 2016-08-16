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
typedef pair<int, int> intPair;
const int INF = (1<<31)-1;
vector<vector<int>> adj;
int main(){
    priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
    int n,m,x; scanf("%d%d%d",&n,&m,&x);
    adj = vector<vector<int>>(n+1, vector<int>(n+1,INF));
    for( int i = 0 ; i < m ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a][b] = c;
    }
    vector<int> come(n+1, INF);
    vector<int> back(n+1, INF);
    pq.push(make_pair(0, x));
    back[x] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if( cost > back[here] ) continue;
//        back[x] = cost;
        for( int next = 1 ; next <= n ; ++next ){
            if(adj[here][next] == INF ) continue;
            int next_cost = adj[here][next] + cost;
            if( back[next] > next_cost ){
                back[next] = next_cost;
                pq.push(make_pair(next_cost, next));
            }
        }
    }
    
    pq.push(make_pair(0, x));
    come[x] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if( cost > come[here] ) continue;
//        come[x] = cost;
        for( int next = 1 ; next <= n ; ++next ){
            if(adj[next][here] == INF ) continue;
            int next_cost = adj[next][here] + cost;
            if( come[next] > next_cost ){
                come[next] = next_cost;
                pq.push(make_pair(next_cost, next));
            }
        }
    }
    int ret = -1;
    for( int i = 1 ; i <= n ; ++i ){
        if( come[i] == INF || back[i] == INF ) continue;
        ret = max(ret, come[i]+back[i]);
    }
    printf("%d",ret);
    return 0;
}