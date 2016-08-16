#include<cstdio>
using namespace std;

int main(){
    int dp[1000001][2];
    int n; scanf("%d",&n);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for( int i = 3 ; i <= n ; ++i ){
        dp[i][0] = (dp[i-2][0]+dp[i-2][1])%15746;
        dp[i][1] = (dp[i-1][1]+dp[i-1][0])%15746;
    }
    printf("%d",(dp[n][0]+dp[n][1])%15746);
    return 0;
}