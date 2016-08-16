#include <cstdio>
#define max(a,b) a>b ? a:b
int dp[1001];
int a[1001];
int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d",&n);
    
    for(int i =0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < n ;i++){
        dp[i] = a[i];
        for(int j =0;j<i;j++){
            if(a[j] <a[i] && dp[j] + a[i] > dp[i]){
                dp[i] = dp[j]+a[i];
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}