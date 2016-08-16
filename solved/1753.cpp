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
typedef pair<int,int> intPair;
const int INF = (1<<31)-1;
int v,e;
map<int, int> adj[20001];
int main(){
    int k;
    scanf("%d%d%d", &v,&e,&k);
    for( int i = 0 ; i < e ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        if(a==b) continue;
        auto it = adj[a].find(b);
        if( it == adj[a].end() ){
            adj[a].insert(make_pair(b, c));
        }
        else{
            (*it).second = min((*it).second, c);
        }
    }
    vector<int> cost(v+1, INF);
    priority_queue<intPair, vector<intPair>, greater<intPair>> q;
    q.push(make_pair(0, k));
    cost[k] = 0;
    while(!q.empty()){
        intPair cur = q.top();
        q.pop();

        for( auto next : adj[cur.second] ){
            int nextCost = cost[cur.second] + next.second;
            if( cost[next.first] <= nextCost ) continue;
            cost[next.first] = nextCost;
            q.push(make_pair(nextCost, next.first));
        }
    }
    for ( int i = 1 ; i <= v ; ++i ){
        if( cost[i] < INF )
            printf("%d\n", cost[i]);
        else
            printf("INF\n");
    }
    return 0;
}