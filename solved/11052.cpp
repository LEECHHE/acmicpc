#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n; scanf("%d",&n);
    int dp[1001] = { 0 };
    int seq[1001];
    for( int i = 1 ; i <= n ; ++i ){
        scanf("%d",&seq[i]);
    }
    
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= i ; ++j){
            dp[i] = max(dp[i],dp[i-j]+seq[j]);
        }
    }
    printf("%d", dp[n]);
    return 0;
}