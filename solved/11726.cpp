#include <cstdio>
using namespace std;
int dp[2][1001] = { 0 };
int n;
int main(){
    int n; scanf("%d",&n);
    dp[0][1] = 1;
    dp[1][2] = dp[0][2] = 1;
    for( int i = 3 ; i <= n ; ++i ){
        dp[0][i] = (dp[0][i-1]+dp[1][i-1])%10007;
        dp[1][i] = (dp[0][i-2]+dp[1][i-2])%10007;
    }
    printf("%d",(dp[0][n]+dp[1][n])%10007);
    return 0;
}