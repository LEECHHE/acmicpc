#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int mod = 1000000;
int dp[2][3][1001] = { 0 };   // [late][notAttend][Day]
int main(){
    dp[0][1][1] = dp[1][0][1] = dp[0][0][1] = 1;
    int n; scanf("%d",&n);
    for( int day = 2 ; day <= n ; ++day ){
        for( int notAttend = 0 ; notAttend < 3 ; ++notAttend ){
            dp[0][0][day] += dp[0][notAttend][day-1];
            dp[1][0][day] += dp[0][notAttend][day-1]+dp[1][notAttend][day-1];
        }
        dp[0][0][day] %= mod;
        dp[1][0][day] %= mod;
        
        dp[0][1][day] = dp[0][0][day-1];
        dp[0][2][day] = dp[0][1][day-1];

        dp[1][1][day] = dp[1][0][day-1];
        dp[1][2][day] = dp[1][1][day-1];
    }
    int ret = 0;
    for( int late = 0 ; late < 2 ; ++late ){
        for ( int notAttend = 0 ; notAttend < 3 ; ++notAttend ){
            ret += dp[late][notAttend][n];
            ret %= mod;
        }
    }
    printf("%d", ret);
    return 0;
}