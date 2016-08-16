#include <cstdio>
using namespace std;

int getMin( int index );
int dp[10001];
int coin[100] = { 0 };
int n, k;
int main(){
    scanf("%d%d", &n,&k);
    for ( int i = 0 ; i <= k ; ++i ) dp[i] = 1<<30;
    for ( int i = 0 ; i < n ; ++i ){
        int temp; scanf("%d",&temp);
        coin[i] = temp;
    }
    dp[0] = 0;
    for( int i = 1 ; i <= k ; ++i ){
        dp[i] = getMin(i)+1;
    }
    if(dp[k] > 1000000) dp[k] = -1;
    printf("%d", dp[k]);
    return 0;
}
int getMin(int index){
    int min = 1<<30;
    for ( int i = 0 ; i < n ; ++i ){
        if( index - coin[i] < 0 ) continue;
        if( min > dp[index-coin[i]] ) min = dp[index-coin[i]];
    }
    return min;
}