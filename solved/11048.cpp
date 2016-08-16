#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int grid[1000][1000];
    for( int i = 0; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            scanf("%d",&grid[i][j]);
        }
    }
    int dp[1000][1000] = {0 };
    dp[0][0] = grid[0][0];
    for( int i = 1 ; i < m ; ++i ){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    for( int j = 1; j < n ; ++j ){
        dp[j][0] = dp[j-1][0]+grid[j][0];
    }
    for ( int i = 1 ; i < n ; ++i ){
        for( int j = 1 ; j < m ; ++j ){
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]))+grid[i][j];
        }
    }
    printf("%d", dp[n-1][m-1]);
    return 0;
}