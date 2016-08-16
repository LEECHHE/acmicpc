#include <cstdio>
using namespace std;

int sticker[2][100000];
int dp[3][100000];
int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        for( int j = 0; j < 2 ; ++j){
            for( int i = 0 ; i < n ; ++i ){
                scanf("%d",&sticker[j][i]);
            }
        }
        for( int i = 0; i < 3 ; ++i )
            for( int j = 0 ; j < n ; ++j)
                dp[i][j] = 0;
        dp[1][0] = sticker[0][0];
        dp[2][0] = sticker[1][0];
        
        for ( int i = 1 ; i < n ; ++i ){
            dp[0][i] = max(max(dp[0][i-1],dp[1][i-1]),dp[2][i-1]);
            dp[1][i] = max(dp[0][i-1],dp[2][i-1])+sticker[0][i];
            dp[2][i] = max(dp[0][i-1],dp[1][i-1])+sticker[1][i];
        }
        printf("%d\n",max(max(dp[0][n-1],dp[1][n-1]),dp[2][n-1]));
    }
    return 0;
}