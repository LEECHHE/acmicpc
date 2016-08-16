#include <cstdarg>
#include <cstdio>
using namespace std;
unsigned long long dp[10][1001];
unsigned long long sumAdjacent(int prev, int length, ...){
    va_list values;
    va_start(values, length);
    unsigned long long result = dp[va_arg(values, int)][prev];
    for ( int i = 1 ; i < length ; ++i ){
        result = (result + dp[va_arg(values, int)][prev]) % 1234567;
    }
    va_end(values);
    
    return result;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int N; scanf("%d",&N);
        for( int i = 0 ; i < 10 ; ++i ) dp[i][1] = 1;
        for( int i = 2 ; i <= N ; ++i ){
            dp[0][i] = sumAdjacent(i-1, 1, 7);
            dp[1][i] = sumAdjacent(i-1, 2, 2,4);
            dp[2][i] = sumAdjacent(i-1, 3, 1,3,5);
            dp[3][i] = sumAdjacent(i-1, 2, 2,6);
            dp[4][i] = sumAdjacent(i-1, 3, 1,5,7);
            dp[5][i] = sumAdjacent(i-1, 4, 2,4,6,8);
            dp[6][i] = sumAdjacent(i-1, 3, 3,5,9);
            dp[7][i] = sumAdjacent(i-1, 3, 4,8,0);
            dp[8][i] = sumAdjacent(i-1, 3, 5,7,9);
            dp[9][i] = sumAdjacent(i-1, 2, 6,8);
        }
        unsigned long long result = 0;
        for( int i = 0 ; i < 10 ; ++i ) result = (result+dp[i][N])%1234567;
        printf("%lld\n", result);
    }
    return 0;
}