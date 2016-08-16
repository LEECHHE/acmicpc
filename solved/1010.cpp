#include <cstdio>
using namespace std;

unsigned long long dp[31][31] = { 0 };      //dp[N][
int N, M;   // N =< M;

unsigned long long combination( int n , int m );
int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &N, &M);
        for ( int j = 0 ; j <= M ; j++ ){
            for ( int i = 0 ; i <= N ; ++i ){
                dp[i][j] = combination( i, j );
            }
        }
        printf("%lld\n" , combination( N, M) );
    }

    return 0;
}
unsigned long long combination( int n, int m ){ // mCn
    if ( m == 0 ) return 0;
    if ( n == 0 ) return 1;
    if ( n == m ) return 1;
    
    return dp[n-1][m-1] + dp[n][m-1];
}