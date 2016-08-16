#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10][1001] = { 0 };
int solve(int k, int len){
    if( len == 0 ) return 0;
    if( len == 1 ) return 1;
    int& ret = dp[k][len];
    if( ret != -1 ) return ret;
    ret = 0;
    for( int i = k ; i < 10 ; ++i ){
        ret += solve(i, len-1);
        ret %= 10007;
    }
    return ret;
}
int main(){
    int n; scanf("%d",&n);
    memset(dp, -1, sizeof(dp));
    int ret =0;
    for( int i = 0 ; i < 10 ; ++i ){
        ret += solve(i, n);
        ret %= 10007;
    }
    printf("%d",ret);
    return 0;
}