#include <cstdio>
using namespace std;
const int mod = 1000000000;
int main(){
    int n; scanf("%d",&n);
    int dp[10][101] = { 0 };
    for( int i = 1 ; i <= 9 ; ++i ){
        dp[i][1] = 1;
        dp[i][2] = 2;
    }
    dp[0][2] = dp[1][2] = dp[9][2] = 1;
    for( int i = 3 ; i <= n ; ++i ){
        dp[0][i] = dp[1][i-1];
        for( int j = 1 ; j <= 8 ; ++j){
            dp[j][i] = (dp[j-1][i-1]+dp[j+1][i-1])%mod;
        }
        dp[9][i] = dp[8][i-1];
    }
    int ret = 0;
    for( int i = 0 ; i <= 9 ; ++i ){
        ret += dp[i][n];
        ret %= mod;
    }
    printf("%d",ret);
    return 0;
}