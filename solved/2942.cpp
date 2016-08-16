#include <cstdio>
#include <cmath>
using namespace std;

int GCD(int _a, int _b){
    int a = _a;
    int b = _b;
    int t;
    while ( b != 0 ){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main () {
    int R, G;
    scanf("%d %d", &R, &G);
    int gcd = GCD(R, G);
    for ( int i = 1 ; i <= sqrt(gcd) ; ++i )
        if ( !( R % i) && !( G % i ) ){
            printf("%d %d %d\n", i, R/i, G/i );
            if ( i == sqrt(gcd)) break;
            else printf("%d %d %d\n", gcd/i, R/(gcd/i) , G/(gcd/i));
        }
    return 0;
}