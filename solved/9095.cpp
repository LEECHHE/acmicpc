#include <cstdio>
using namespace std;

unsigned long long factorial( int n ){
    if( n == 0 ) return 1;
    return n * factorial(n-1);
}
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        unsigned long long result = 0;
        for ( int c = 0 ; c <= n/3 ; ++c ){
            for ( int b = 0 ; b <= (n-3*c)/2 ; ++b ){
                result += factorial(n-2*c-b) / factorial(b) / factorial(c) / factorial(n-3*c-2*b);
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}