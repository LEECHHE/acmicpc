#include<iostream>
#include<cstring>
using namespace std;
const int MOD = 1000007;
int dp[405][405];
int comb(int n, int r){
    if( n == r || r == 0 ) return 1;
    int& ret = dp[n][r];
    if( ret != -1 ) return ret;
    return ret = (comb(n-1,r-1)%MOD+comb(n-1,r)%MOD)%MOD;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%lld",((long long)comb(c+d-2,d-1)*(long long)comb(a+b-c-d,b-d))%MOD);
    return 0;
}