#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector< vector<int> > adj;
vector<bool> visited;
int n,m;

int dfs(int k) {
	int count = 1;
	printf("node: %d\n", k);
	for(auto next : adj[k]) {
		if (!visited[next]) {
			visited[next] = true;
			count += dfs(next);
		}
	}
	return count;
}

int max(int a, int b) { return a > b ? a : b; }
int main() {
	scanf("%d%d", &n,&m);
	adj = vector< vector<int> >(n + 1);
	for( int i = 0 ; i < m ; ++i ) {
		int a,b; scanf("%d%d", &a,&b);
		adj[b].push_back(a);
	}
	vector<int> ans;
	int count = -1;
	for ( int start = 1 ; start <= n ; ++start) {
		visited = vector<bool> (n+1, false);
		visited[start] = true;
		int cur = dfs(start);
		printf("start: %d, count: %d\n", start, cur);
		if (cur == count) {
			ans.push_back(start);
		} else if (cur > count) {
			ans.clear();
			ans.push_back(start);
			count = cur;
		}
	}
	for (auto a : ans) {
		printf("%d ", a);
	}
	return 0;
}
