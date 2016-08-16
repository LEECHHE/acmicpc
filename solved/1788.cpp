#include <cstdio>
using namespace std;
int fib[1000001] = { 0,1 };
int main(){
    for( int i = 2 ; i <= 1000000 ; ++i ){
        fib[i] = (fib[i-1]+fib[i-2])%1000000000;
    }
    int n; scanf("%d",&n);
    if( n > 0 ) printf("1");
    else if( n == 0 ) printf("0");
    else{
        n%2? printf("1") : printf("-1");
    }
    printf("\n%d",n < 0 ? fib[-n] : fib[n]);
    return 0;
}