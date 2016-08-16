#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1000][1000] = { 0 };
char grid[1005][1005];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i+=scanf("%s",grid[i]));
    for( int i = 0 ; i < n ; ++i ){
        dp[i][0] = grid[i][0]-'0';
    }
    for( int j = 0 ; j < m ; ++j){
        dp[0][j] = grid[0][j]-'0';
    }
    for( int i = 1 ; i < n ; ++i ){
        for (int j = 1; j < m ; ++j) {
            if( grid[i][j] == '0') continue;
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+(grid[i][j]=='1');
        }
    }
    int ret = dp[0][0];
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            ret = max(ret, dp[i][j]);
        }
    }
    printf("%d",ret*ret);
    return 0;
}