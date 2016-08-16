#include <cstdio>
#include <algorithm>
using namespace std;
int seq[1000]={0};
int dp[1000]={0};
int main(){
    int n; scanf("%d",&n);
    for( int i =0 ; i < n ; ++i ){
        dp[i] = 50000;
        scanf("%d",&seq[i]);
    }
    dp[0] = 0;
    for( int i = 0; i < n ; ++i ){
        for( int step = 1 ; step <= seq[i] ; ++step ){
            int next = i+step;
            if( next < n ){
                dp[next] = min(dp[next],dp[i]+1);
            }
        }
    }
    if( dp[n-1] == 50000 ) dp[n-1] = -1;
    printf("%d", dp[n-1]);
    return 0;
}