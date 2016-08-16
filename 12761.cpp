#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> state;
int dx[] = {1,0,0};
int dir[] = { -1, 1};
int n,m;
int dist[100001];
const int INF = 987654321;
int main(){
	scanf("%d%d%d%d",&dx[1],&dx[2],&n,&m);
	for( int i = 0 ; i <= 100000 ; ++i ) dist[i] = INF;
	queue<state> q;
	q.push(state(n,0));
	dist[n] = 0;
	while(!q.empty()){
		int pos = q.front().first;
		int d = q.front().second;
		q.pop();
		printf("(%d,%d)\n", pos, d);
		if( pos == m ) break;
		for( int di = 0 ; di < 2 ; ++di ){
			for( int k = 0 ; k < 3 ; ++k ){
				int next_pos = pos+dir[di]*dx[k];
				if( next_pos < 0 || next_pos > 100000 ) continue;
				if( dist[next_pos] <= d+1 ) continue;
				dist[next_pos] = d+1;
				q.push(state(next_pos,d+1));
			}
			for( int i = 0 ; i < 2 ; ++i ){
				int j = pos+pos*dx[i+1]*dir[di];
				if( 0 <= j && j <= 100000 && dist[j] > d+1){
					dist[j] = d+1;
					q.push(state(j,d+1));
				}
			}
		}
	}
	printf("%d\n",dist[m]);	
	
	return 0;
}
