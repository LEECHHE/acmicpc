#include<cstdio>
#include<stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
vector<int> edges[100];
int a, b;
int ans = -1;
void dfs(int current, int count, bool *visited){
	if (visited[current]) return;
	if (current == b-1) {
		ans = count;
		visited[current] = true;
		return;
	}
	visited[current] = true;
	for (auto person : edges[current]){
		dfs(person, count + 1, visited);
	}
}
int main(){
	bool visited[100] = { false };
	int n; scanf("%d", &n);
	scanf("%d%d", &a, &b);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i){
		int p,q; scanf("%d%d", &p,&q);
		edges[p-1].push_back(q-1);
		edges[q-1].push_back(p-1);
	}

	int count = 0;
	dfs(a - 1, 0, visited);

	printf("%d", ans);

	return 0;
}