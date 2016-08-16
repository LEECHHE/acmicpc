#include<iostream>
#include<cstring>
using namespace std;
int n,m,k;
int cost[101][101];
int tim[101][101];
const int INF = 50000;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for( int i = 1 ; i <= n ; ++i ){
			for( int j = 1 ; j <= n ; ++j ){
				cost[i][j] = tim[i][j] = INF;
			}
		}
		
		for( int i = 0 ; i < k ; ++i ){
			int u,v,x,d; scanf("%d%d%d%d",&u,&v,&x,&d);
			cost[u][v] = x;
			tim[u][v] = d;
		}	

		//floyd-warshall
		for( int i = 1 ; i <= n ; ++i ){
			for( int j = 1 ; j <= n ; ++j ){
				if( i == j ) continue;
				for( int k = 1; k <= n ; ++k ){
					if( cost[i][k] == INF || cost[k][j] == INF ) continue; 
					cost[i][j] = min(cost[i][k]+cost[k][j], cost[i][j]);
					tim[i][j] = min(tim[i][k]+tim[k][j], tim[i][j]);
				}
			}
		}
		for( int i = 1 ; i <= n ; ++i ){
			printf("%d(%d,%d) ", i, cost[1][i], tim[1][i]);
		}

		if( cost[1][n] > m ){
			printf("Poor KCM\n");
			continue;
		}
		else{
			printf("%d\n",tim[1][n]);
		}
	}
	return 0;
}
