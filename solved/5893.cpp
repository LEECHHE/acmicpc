#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char num[1001];
    char ret[1011];
    for( int i = 0 ; i < 10 ; ++i ) ret[i] = '0';
    scanf("%s", num);
    memcpy(ret+4, num, sizeof(num));
    int idx = (int)strlen(num)-1;
    int carry = 0;
    for( ; idx >= 0 ; --idx){
        int a = ret[idx]-'0', b = num[idx]-'0';
        ret[idx] = (a+b+carry)%2+'0';
        carry = a+b+carry > 1;
    }
    if( carry ) printf("1");
    printf("%s", ret);
    return 0;
}