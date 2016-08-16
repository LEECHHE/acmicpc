#include <cstdio>
#include <cstring>
using namespace std;
int n,s,m;
int v[101];
int dp[101][1005];
int max(int a, int b){
    return a > b ? a : b;
}
int solve(int idx, int p){
    if( p > m || p < 0 ) return -2;
    if( idx == n ) return p;
    int& ret = dp[idx][p];
    if( ret != -1 ) return ret;
//    printf("call f(%d,%d)\n",idx,p);
    return ret = max(solve(idx+1,p+v[idx+1]),solve(idx+1, p-v[idx+1]));
}
int main(){
    scanf("%d%d%d",&n,&s,&m);
    memset(dp, -1, sizeof(dp));
    for( int i = 1 ; i<=n; i += scanf("%d",&v[i]));
    int ret = solve(0, s);
    if ( ret < 0 ) ret = -1;
    printf("%d", ret);
    return 0;
}