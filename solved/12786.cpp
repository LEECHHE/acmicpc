#include <iostream>
#include <cstring>
using namespace std;
bool tree[105][25] = { false };
int dp[105][25][55];
int n,k;
int max(int& a, int& b) { return a > b ? a : b; }
int solve(int idx, int h, int step){
    if( h > 20 ) h = 20;
    if(h <= 0 || !tree[idx][h] || step < 0 ) return -2;
    if( idx == n ) return step;
    int& ret = dp[idx][h][step];
    if( ret != -1 ) return ret;
//    printf("visit %d on height %d, step : %d\n", idx, h, step);
    ret = max(solve(idx+1,h,step),
              max( solve(idx+1,h+1,step),
                  max(solve( idx+1, h-1, step ),solve( idx+1, 2*h, step ))));
    for( int i = 1 ; i <= 20 ; ++i ){
        if( tree[idx+1][i] ) ret=max(ret,solve(idx+1,i,step-1));
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);
    for( int i = 1 ; i <= n ; ++i ){
        int m; scanf("%d",&m);
        for( int j = 0 ; j < m ; ++j ){
            int t; scanf("%d",&t);
            tree[i][t] = true;
        }
    }
    tree[0][1] = true;
    memset(dp,-1,sizeof(dp));
    int ret = solve(0,1,k);
    if( ret < 0 ) ret = -1;
    else ret = k-ret;
    printf("%d", ret);
    return 0;
}