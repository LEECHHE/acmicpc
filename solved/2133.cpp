#include <cstdio>
using namespace std;

unsigned long long dp[31] = { 0 };
unsigned long long tiling( int n );
int main(){
    int N;
    scanf( "%d" , &N );
    
    dp[2] = 3;
    for ( int i = 2 ; i <= N/2 ; i++ ){
        dp[2 * i] = tiling( i );
    }
    printf("%llu", dp[N]);
    
    return 0;
}

unsigned long long tiling( int n ){
    if ( 2 * n - 2 < 0 ) return 0;
    unsigned long long& ret = dp[2 * n];
    ret = 3 * dp[2 * n - 2];
    int temp = 2 * n - 2;

    while ( (temp -= 2) >= 2 ) {
        ret += 2 * dp[temp];
    }
    ret += 2;
    
    return ret;
}