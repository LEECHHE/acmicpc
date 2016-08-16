#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
char num[41];
int len;
bool isIncluded(int idx){
    if ( idx >= len-1 ) return false;
    if( num[idx] == '0' ) return false;
    if( num[idx] >= '4' ) return false;
    if( num[idx] == '3' ) return num[idx+1]<= '4';
    return true;
}
ll dp[2][40];   //0:1자리, 1: 2자리로 끝
int main(){
    scanf("%s", num);
    len = (int)strlen(num);
    dp[0][0] = num[0]!='0'; dp[1][1] = isIncluded(0);
    dp[1][0] = 0; dp[0][1] = (len>1 && num[1] !='0');
    for( int i = 2 ; i < len ; ++i ){
        dp[0][i] = num[i] == '0' ? 0 : dp[0][i-1]+dp[1][i-1];
        dp[1][i] = isIncluded(i-1)? dp[0][i-2]+dp[1][i-2] : 0;
    }
    printf("%lld",dp[0][len-1]+dp[1][len-1]);
    return 0;
}