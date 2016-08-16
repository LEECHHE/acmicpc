#include <cstdio>
using namespace std;

int max(int a, int b){
    return a > b? a : b;
}

int stair[301] = { 0 };
int dp[301][2] = { 0 };
int n;
int main(){
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; ++i ) scanf("%d",&stair[i]);
    dp[1][0] = 0;
    dp[1][1] = stair[1];
    
    dp[2][0] = stair[2];
    dp[2][1] = dp[1][1]+stair[2];
    for( int i = 3 ; i <= n ; ++i ){
        dp[i][0] = max(dp[i-2][0], dp[i-2][1])+stair[i];
        dp[i][1] = dp[i-1][0]+stair[i];
    }
    printf("%d", max(dp[n][0],dp[n][1]));
    return 0;
}