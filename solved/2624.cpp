#include <cstdio>
using namespace std;
int t,k;
int coin[101];
int cnt[101];
int dp[101][10001]={0};
int main(){
    scanf("%d%d",&t,&k);
    dp[0][0] = 1;
    for( int i = 1 ; i <= k ; ++i ){
        dp[i][0] = 1;
        scanf("%d%d",&coin[i],&cnt[i]);
    }
    for ( int kind = 1 ; kind <= k ; ++kind ){
        for ( int money = 1 ; money <= t ; ++money ){
            for( int c = 0 ; c <= cnt[kind] ; ++c ){
                if( money < c*coin[kind] ) break;
                dp[kind][money] += dp[kind-1][money-c*coin[kind]];
            }
        }
    }
    printf("%d", dp[k][t]);
    return 0;
}