#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll factorial[11] = { 1 };
ll dp[11][101][101][101];
int n,r,g,b;
ll solve(int lv, int red, int green, int blue){
    if( red > r || green > g || blue > b ) return 0;
//    printf("called %d(%d,%d,%d)\n",lv,red,green,blue);
    if( lv > n ) return 1;
    ll& ret = dp[lv][red][green][blue];
    if( ret != -1 ) return ret;
    ret = 0;
    if( lv % 3 == 0 ){
        int add = lv/3;
        ret += solve(lv+1,red+add,green+add,blue+add)*(factorial[lv]/factorial[add]/factorial[add]/factorial[add]);
    }
    if( lv % 2 == 0 ){
        int add = lv/2;
        ret += (solve(lv+1,red+add,green+add,blue) + solve(lv+1,red+add,green,blue+add)
        +solve(lv+1,red,green+add,blue+add))*(factorial[lv]/factorial[add]/factorial[add]);

    }
    ret += solve(lv+1,red+lv,green,blue)+solve(lv+1,red,green+lv,blue)+solve(lv+1,red,green,blue+lv);
    return ret;
}
int main(){
    for( int i = 1 ; i <= 10 ; ++i ){
        factorial[i] = factorial[i-1]*i;
    }
    scanf("%d%d%d%d",&n,&r,&g,&b);
    memset(dp,-1,sizeof(dp));
    printf("%lld", solve(1,0,0,0));
    return 0;
}