#include <cstdio>
#include <algorithm>
using namespace std;

int triangle[125250];
int dp[125250] = { -1 };

int main(){
    int n;
    scanf( "%d", &n );
    
    int bound = n * ( n + 1 ) / 2;
    for ( int i = 0 ; i < bound ; i++ )
        scanf( "%d", &triangle[i] );
    
    dp[0] = triangle[0];
    
    for ( int i = 2 ; i <= n ; i++ ){
        int start = (i-1) * i / 2;
        int end = (i-1) * (i+2) / 2;
        dp[ start ] = dp[ (i-2) * (i-1) / 2 ] + triangle[ start ];      //left bound
        dp[ end ] = dp[ (i-2) * (i+1) / 2 ] + triangle [ end ]; //right bound
        for ( int j = start + 1 ; j < end ; j++ ){
                dp[j] = max ( dp[j-i], dp[j-i+1] ) + triangle[j];
        }
    }
    int result = -1;
    bound = (n-1) * (n+2) / 2;
    for ( int i = (n-1) * n / 2 ; i <= bound ; i++ ){
        if ( result < dp[i] ) result = dp[i];
    }
    printf("%d", result );
    return 0;
}