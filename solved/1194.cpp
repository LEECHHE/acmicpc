#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> intPair;
typedef pair<int,intPair> state;
const int dx[] = { 1,-1,0,0};
const int dy[] = { 0,0,1,-1};
bool visited[1<<6][55][55];
char grid[55][55];
bool isValid(int key, int x, int y){
	char c = grid[x][y];
	if( 'A' <= c && c <= 'F' ) return key&(1<<(c-'A'));
	return c != '#';
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	intPair start = intPair(-1,-1);
	for( int i = 1 ; i <= n ; ++i ){
		scanf("%s", grid[i]+1 );
		grid[i][0] = grid[i][m+1] = '#';
		if( start.first < 0 ){
			for( int j = 1 ; j <= m ; ++j ){
				if( grid[i][j] == '0' ) start = intPair(i,j);
			}
		}
	}
	for( int i = 1 ; i <= m ; ++i ) grid[0][i] = grid[n+1][i] = '#';
	queue<state> q;
	visited[0][start.first][start.second] = true;
	q.push(state(0,start));
	int ret = -1;
	int cnt = 0;
	while(!q.empty()){
		int len = q.size();
		++cnt;
		for( int i = 0 ; i < len ;++i ){
			int key = q.front().first;
			intPair pos = q.front().second;
			q.pop();
			
			int x = pos.first;
			int y = pos.second;
			if( 'a' <= grid[x][y] && grid[x][y] <= 'f' ){
				key |= 1<<(grid[x][y]-'a');
			}
			for( int d = 0 ; d < 4 ; ++d ){
				int cx = x+dx[d];
				int cy = y+dy[d];
				if(!isValid(key,cx,cy) || visited[key][cx][cy] ) continue;
				visited[key][cx][cy] = true;
				if( grid[cx][cy] == '1') {
					ret = cnt;
					break;
				}
				q.push(state(key,intPair(cx,cy)));
			}
			if( ret >= 0 ) break;
		}
		if( ret >= 0 ) break;
	}
	printf("%d",ret);
	return 0;
}