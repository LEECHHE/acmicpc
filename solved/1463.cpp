#include <cstdio>
using namespace std;
#define MAX 1000001
int dp[3][1000001];
int min(int index){
    int result = MAX;
    for( int i = 0 ; i < 3 ; ++i )
        if( result > dp[i][index] ) result = dp[i][index];
    return result;
}
int main(){
    int N; scanf("%d",&N);
    for( int i = 0 ; i < N ; ++i ){
        dp[0][i] = dp[1][i] = dp[2][i] = MAX;
    }
    dp[0][N] = dp[1][N] = dp[2][N] = 0;
    //run DP
    for( int i = N; i >= 1 ; --i ){
        if( i % 3 == 0 ) dp[0][i/3] = min(i) + 1;
        if( i % 2 == 0 ) dp[1][i/2] = min(i) + 1;
        dp[2][i-1] = min(i) + 1;
    }
    printf("%d", min(1));
    return 0;
}