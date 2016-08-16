#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int coin[20];
int dp[20][10005];
int max(int a, int b){
    return a > b ? a : b;
}
int solve(int kind, int p){
    if( p > m ) return 0;
    if( p == m ) return 1;
    int& ret = dp[kind][p];
    if( ret != -1 ) return ret;
    ret = 0;
    for( int i = kind; i < n ; ++i ){
        ret += solve(i, p+coin[i]);
    }
    return ret;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for( int i = 0 ; i<n; i += scanf("%d",&coin[i]));
        scanf("%d",&m);
        memset(dp, -1, sizeof(dp));
        int ret = solve(0, 0);
        printf("%d\n", ret);
    }
    return 0;
}