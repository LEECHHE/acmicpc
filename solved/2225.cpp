#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
int seq[201];
int dp[201][201];
const int mod = 1000000000;
int solve(int cnt, int idx){
    if( cnt == k ) return idx == n;
    if( idx > n ) return 0;
    int& ret = dp[cnt][idx];
    if(ret != -1 ) return ret;
    ret = 0;
    for( int i = 0 ; i <= n ; ++i ){
        ret += solve(cnt+1, idx+i);
        ret %= mod;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);
    memset(dp, -1, sizeof(dp));
    
    printf("%d", solve(0, 0));
    return 0;
}