#include<iostream>
using namespace std;
int dp[1005];
int seq[1005];
int max(int a, int b){ return a>b?a:b; }
int main(){
    int n; scanf("%d",&n);
    for( int i = 1 ; i <= n ; ++i ){
        scanf("%d",&seq[i]);
        dp[i] = 1;
    }
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j < i ; ++j ){
            if( seq[j]<seq[i] )
                dp[i] = max(dp[j]+1,dp[i]);
        }
    }
    int ret = -1;
    for( int i = 1 ; i <= n ; ++i ){
        ret = max(ret, dp[i]);
    }
    printf("%d",ret);
    return 0;
}