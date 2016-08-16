#include <cstdio>
#include <cstring>
using namespace std;
int max(int a, int b){
    return a > b ? a : b;
}
int grid[500][500];
int dp[500][500];
int n;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int solve(int x, int y){
    int& ret = dp[x][y];
    if( ret != -1 ) return ret;
    ret = 1;
    int adj = 0;
    for( int dir = 0 ; dir < 4 ; ++dir ){
        int cx = x+dx[dir], cy = y+dy[dir];
        if( cx < 0 || cx >= n || cy < 0 || cy >= n ) continue;
        if( grid[cx][cy] > grid[x][y] )
            adj = max(adj,solve(cx, cy));
    }
    return ret += adj;
}
int main(){
    scanf("%d",&n);
    memset(dp, -1, sizeof(dp));
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d",&grid[i][j]);
        }
    }
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            ret = max(ret,solve(i, j));
        }
    }
    printf("%d",ret);
    return 0;
}