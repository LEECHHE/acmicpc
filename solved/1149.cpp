#include <algorithm>
#include <cstdio>
using namespace std;

int dp[1000][3] = { { -1, -1, -1 } };
int getCost( int, int );
int main(){
    int N;
    scanf( "%d", &N );
    
    scanf("%d %d %d", &dp[0][0], &dp[0][1], &dp[0][2] );
    
    for ( int i = 1 ; i < N ; i++ ){
        int temp[3];
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2] );
        
        for ( int j = 0 ; j < 3 ; j++ ){
            dp[i][j] = getCost( i - 1 , j ) + temp[j];
        }
    }
    printf ("%d", min( dp[N-1][0], min( dp[N-1][1], dp[N-1][2] )));
    return 0;
}

int getCost( int n, int color ){
    if ( color == 0 ){
        return min ( dp[n][1], dp[n][2] );
    }
    else if ( color == 1 ){
        return min ( dp[n][0], dp[n][2] );
    }
    else return min ( dp[n][0], dp[n][1] );
}