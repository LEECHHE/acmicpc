#include <cstdio>
using namespace std;

int graph[100000][3];
int dp[100000][3] = { 0 };
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int caseNumber = 1;
    int n; scanf("%d", &n);
    while( n > 0 ){
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < 3 ; ++j )
                graph[i][j] = 0;
        }
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d%d%d",&graph[i][0],&graph[i][1],&graph[i][2]);
        }
        dp[0][0] = 987654321;
        dp[0][1] = graph[0][1];
        dp[0][2] = dp[0][1]+graph[0][2];
        for ( int i = 1 ; i < n ; ++i ){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + graph[i][0];
            dp[i][1] = min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])))+ graph[i][1];
            dp[i][2] = min(dp[i][1], min(dp[i-1][1], dp[i-1][2])) + graph[i][2];
        }
        printf("%d. %d\n", caseNumber++, dp[n-1][1]);
        scanf("%d",&n);
    }
    return 0;
}