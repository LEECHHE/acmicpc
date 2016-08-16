#include <cstdio>
#include <cstring>
using namespace std;

int main ( void ){
    unsigned long long fib[2] = { 0 , 1 };
    int N;
    scanf ( "%d", &N );
    
    if ( N < 2 ){
        printf( "%lld", fib[N] );
        return 0;
    }
    int n = N;
    while ( n-- ){
        if( n % 2 ) fib[1] = fib[0] + fib[1];
        else fib[0] = fib[0] + fib[1];
    }
    if ( N % 2 ) printf( "%lld" , fib[1] );
    else printf( "%lld" , fib[0] );
    return 0;
}