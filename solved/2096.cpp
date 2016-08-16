#include <cstdio>
using namespace std;
int board[100000][3];
int dp[100000][3];
int min( int current, int upperLine ){
    int result = 1<<30;
    int start = 0, end = 3;
    if ( current == 0 ) end = 2;
    else if ( current == 2 ) start = 1;
    for ( int i = start ; i < end ; ++i ){
        if(result > dp[upperLine][i]) result = dp[upperLine][i];
    }
    return result;
}
int max( int current, int upperLine ){
    int result = -1;
    int start = 0, end = 3;
    if ( current == 0 ) end = 2;
    else if ( current == 2 ) start = 1;
    for ( int i = start ; i < end ; ++i ){
        if(result < dp[upperLine][i]) result = dp[upperLine][i];
    }
    return result;
}
int main(){
    int N; scanf("%d", &N);
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < 3 ; ++j ) scanf("%d", &board[i][j]);
    }
    dp[0][0] = dp[0][0] = board[0][0];
    dp[0][1] = dp[0][1] = board[0][1];
    dp[0][2] = dp[0][2] = board[0][2];
    int r1 = -1;
    for ( int i = 1 ; i < N ; ++i ){
        dp[i][0] = max( 0 , i-1 ) + board[i][0];
        dp[i][1] = max( 1 , i-1 ) + board[i][1];
        dp[i][2] = max( 2 , i-1 ) + board[i][2];
    }
    for( int i = 0 ; i < 3 ; ++i ){
        if( r1 < dp[N-1][i] ) r1 = dp[N-1][i];
    }
    for ( int i = 1 ; i < N ; ++i ){
        dp[i][0] = min( 0 , i-1 ) + board[i][0];
        dp[i][1] = min( 1 , i-1 ) + board[i][1];
        dp[i][2] = min( 2 , i-1 ) + board[i][2];
    }
    int r2 = 1<<30;
    for( int i = 0 ; i < 3 ; ++i ){
        if( r2 > dp[N-1][i] ) r2 = dp[N-1][i];
    }
    printf("%d %d", r1, r2);
    return 0;
}