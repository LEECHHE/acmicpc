#include <cstdio>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int n; scanf("%d",&n);
    int wine[10000];
    int dp[10000][3] = { 0 };
    for ( int i = 0 ; i < n ; ++i )
        scanf("%d",&wine[i]);
    dp[0][1] = wine[0];
    dp[1][0] = dp[0][1];
    dp[1][1] = wine[1];
    dp[1][2] = dp[0][1]+wine[1];
    for( int i = 2 ; i < n ; ++i ){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = max(dp[i-1][0], dp[i-2][0])+wine[i];
        dp[i][2] = dp[i-1][1]+wine[i];
    }
    printf("%d",max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
    return 0;
}