#include <cstdio>
#include <cstring>
using namespace std;
int dp[5001] = { 0 };
const int mod = 1000000;
bool isValid(char a, char b){
    if( a == '0' || a >= '3' ) return 0;
    if( a=='2' && b >= '7' ) return 0;
    return 1;
}
int main(){
    char num[5001]; scanf("%s", num);
    
    int len = (int)strlen(num);
    dp[0] = (num[0] != '0');
    
    if( len > 1){
        dp[1] = isValid(num[0], num[1])+(num[0]!= '0' &&num[1] != '0');
    }
    for ( int i = 2 ; i < len ; ++i ){
        if( num[i] != '0' ){
            dp[i] = dp[i-1];
        }
        if( isValid(num[i-1], num[i])){
            dp[i] += dp[i-2];
        }
        dp[i] %= mod;
    }
    printf("%d",dp[len-1]);
    return 0;
}