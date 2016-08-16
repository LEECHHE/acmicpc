#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    while (1) {
        int n,m; scanf("%d%d",&n,&m);
        if( n == 0 && m == 0 ) break;
        int mat[1000][1000];
        for( int i =0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                scanf("%d",&mat[i][j]);
            }
        }
        int dp[1000][1000] = { 0 };
        memcpy(dp[0], mat[0], sizeof(mat[0]));
        for( int i = 1 ; i < n ; ++i ){
            dp[i][0] = mat[i][0];
        }
        for( int i = 1 ; i < n ; ++i ){
            for( int j = 1 ; j < m ; ++j ){
                if( mat[i][j] == 0 ) continue;
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+mat[i][j];
            }
        }
        int ret = dp[0][0];
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
               ret = max(ret,dp[i][j]);
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}