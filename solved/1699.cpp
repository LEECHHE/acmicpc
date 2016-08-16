#include <cstdio>
#include <algorithm>
using namespace std;
int p2[318];
int dp[100001] = { 0 };
int main(){
    for( int i = 1 ; i <= 100000 ; ++i ){
        dp[i] = 100000;
    }
    for( int i = 1 ; i<=317; ++i){
        p2[i] = i*i;
//        dp[i*i] = 1;
    }
    for( int i = 1 ; i <= 100000 ; ++i ){
        for (int j = 1; p2[j] <= i; ++j) {
            dp[i] = min(dp[i-p2[j]]+1, dp[i]);
        }
    }
    int n; scanf("%d",&n);
    printf("%d", dp[n]);
    return 0;
}