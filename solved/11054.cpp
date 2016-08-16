#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int seq[1005];
int dp[2][1005];
int max(int a, int b){
    return a > b ? a : b;
}
int solve(int up, int idx){
    if( idx >= n ) return 0;
    int& ret = dp[up][idx];
    if( ret != -1 ) return ret;
    ret = 1;
    for ( int i = idx+1; i < n ; ++i) {
        if( up == 1 && seq[idx] < seq[i])
            ret = max(ret, solve(1, i)+1);
        if( seq[idx] > seq[i])
            ret = max(ret, solve(0, i)+1);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i<n; i += scanf("%d",&seq[i]));
    memset(dp, -1, sizeof(dp));
    int ret = solve(0, 0);

    for( int i = 0 ; i < n ; ++i ){
        ret = max(ret,max(solve(1, i),solve(0, i)));
    }

    printf("%d", ret);
    return 0;
}