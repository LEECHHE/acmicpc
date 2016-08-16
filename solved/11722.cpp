#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int seq[1000], n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    int dp[1000] = { 0 };
    for( int i = 0 ; i < n ; ++i ){
        dp[i] = 1;
    }    
    int ret = 1;
    for( int i = 1 ; i < n ; ++i ){
        for( int j = 0 ; j < i ; ++j ){
            if( seq[i]<seq[j] && dp[i] < dp[j]+1){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ret = max(ret,dp[i]);
    }
    printf("%d", ret);
    return 0;
}