#include<iostream>
#include<vector>

using namespace std;
int n,m;
const int INIT = -1000000000;
vector<vector<vector<int> > > dp;
vector<vector<int> > grid;
bool visited[1005][1005] = { false };
int solve(int x, int y, int dir){
	if( x < 0 || y < 0 || x >= n || y >= m ) return 2*INIT;
	if ( x == n-1 && y == m-1 ) return grid[n-1][m-1];
	if ( visited[x][y] ) return 2*INIT;
	int& ret = dp[x][y][dir];
	if( ret != INIT ) return ret;
	printf("visit(%d,%d)\n",x,y);
	ret = grid[x][y];
	visited[x][y] = true;
	ret += max(solve(x,y-1,0),max(solve(x,y+1,1),solve(x+1,y,2)));
	visited[x][y] = false;
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	dp = vector<vector<vector<int> > >(n,vector<vector<int> >(m,vector<int>(3,INIT)));
	grid = vector<vector<int> >(n,vector<int>(m,INIT));
	for( int i = 0 ; i < n ; ++i ){
		for( int j = 0 ; j < m ; j += scanf("%d",&grid[i][j]));
	}
	printf("%d",solve(0,0,2));	
	return 0;
}
