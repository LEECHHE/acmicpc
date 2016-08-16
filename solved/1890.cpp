#include <cstdio>
using namespace std;

void addValue(int i, int j, unsigned long long value);
int grid[100][100];
unsigned long long dp[100][100] = { 0 };
int n;
int main(){
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d",&grid[i][j]);
        }
    }
    dp[0][0] = 1;
    for( int i = 0; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( i == n-1 && j == n-1 ) break;
            if(dp[i][j] > 0){
                addValue(i+grid[i][j], j, dp[i][j]);
                addValue(i, j+grid[i][j], dp[i][j]);
            }
        }
    }
    printf("%lld",dp[n-1][n-1]);
    return 0;
}
void addValue(int i, int j, unsigned long long value){
    if( i < 0 || j < 0 || i >= n || j >= n ) return;
    dp[i][j] += value;
}