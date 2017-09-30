#include<cstdio>
using namespace std;
int adj[405][405] = { 0 };

int main() {
 	int n, k; scanf("%d%d",&n,&k);
	for (int i = 0; i < k ; ++i) {
		int a,b; scanf("%d%d",&a,&b);
		adj[a][b] = -1;
		adj[b][a] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n ; ++i) {
			for (int j = 1; j <= n ; ++j) {
				if (adj[i][k] == adj[k][j] && adj[i][k] != 0) {
					adj[i][j] = adj[i][k];
				}
			}
		}
	}

	int s; scanf("%d", &s);
	for (int i = 0 ; i < s ; ++i) {
		int a,b; scanf("%d%d", &a, &b);
		printf("%d\n", adj[a][b]);
	}
	return 0;
}
