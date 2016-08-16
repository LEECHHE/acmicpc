#include<iostream>
#include<queue>

using namespace std;
int n,k;
typedef pair<int,int> intPair;
typedef pair<intPair, int> edge;
vector<intPair> adj[100];
int main(){
	scanf("%d%d",&n,&k);
//input
	priority_queue<intPair, vector<intPair>, greater<intPair> > pq;//최소값이 맨 위
	int v; // start
	scanf("%d",&v);
	int cost[10];

	for( int i = 0 ; i < k ; ++i ){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back(intPair(b,c));
	}

	int INF = (1<<31)-1;
	for( int i = 0 ; i <= n ; ++i ){
		cost[i] = INF;
	}
	cost[v] = 0;
	
	for( auto e : adj[v] ){
		//(목적지, 코스트)
		pq.push(intPair(e.first,e.second));
	}
	while(!pq.empty()){
		intPair e = pq.top();
		int cur = e.first;
		int cst = e.second;
		pq.pop();

		if( cst >= cost[cur] ) continue;
		cost[cur] = cst;
		for( auto next : adj[cur] ){
			int next_node = next.first;
			int nxt_cst = cst+next.second;
			if( nxt_cst >= cost[next_node] ) continue;
			
			pq.push(intPair(next_node, nxt_cst));
		}
	}
	for( int i = 1 ; i <= n ; ++i ){
		printf("%d\t", cost[i]);
	}
	return 0;
}
