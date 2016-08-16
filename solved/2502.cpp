#include <cstdio>
using namespace std;
int fib[35] = { 1, 1 };
int main(){
    for( int i = 2 ; i < 35 ; ++i ){
        fib[i] = fib[i-1]+fib[i-2];
    }
    int d, k; scanf("%d%d",&d,&k);
    int cnt[2];
    if( d == 1 ){
        cnt[0] = 1; cnt[1] = 0;
    }
    else if( d == 2 ){
        cnt[0] = 0; cnt[1] = 1;
    }
    else{
        cnt[0] = fib[d-3]; cnt[1] = fib[d-2];
    }
    for( int a = 1 ; ; ++a ){
        if( (k-a*cnt[0])%cnt[1] == 0 ){
            printf("%d\n%d", a, (k-a*cnt[0])/cnt[1]);
            break;
        }
    }
    return 0;
}