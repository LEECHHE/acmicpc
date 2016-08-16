#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> intPair;
const int INF = (1<<31)-1;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    vector<intPair> adj[1001];
    priority_queue<intPair, vector<intPair>, greater<intPair> > pq;
    for( int i = 0 ; i < m ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(c, b));
    }
    int s, d; scanf("%d%d",&s,&d);
    int dist[1001]; for( int i = 0 ; i <= n ; ++i ) dist[i] = INF;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if( cost > dist[cur] ) continue;
        for( auto next : adj[cur] ){
            int next_cost = cost + next.first;
            int node = next.second;
            if( next_cost < dist[node] ){
                dist[node] = next_cost;
                pq.push(make_pair(next_cost,node));
            }
        }
    }
    printf("%d",dist[d]);
    return 0;
}