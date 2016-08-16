#include <cstdio>
#include <cmath>
using namespace std;

double getab( int c, int a ){
    return sqrt( c*c - a*a );
}
int main () {
    int a, b, c;
    int num = 1;
    while(1){
        scanf ( "%d %d %d", &a, &b, &c );
        if ( !a ) break;
        
        printf("Triangle #%d\n", num++ );
        if ( a < 0 ){
            if ( b >= c ){
                printf("Impossible.\n\n");
                continue;
            }
            printf ("a = %.3lf\n\n", getab( c, b) );
            continue;
        }
        else if ( b < 0 ){
            if ( a >= c ){
                printf("Impossible.\n\n");
                continue;
            }
            printf ("b = %.3lf\n\n", getab( c, a) );
            continue;
        }
        else{
            printf("c = %.3lf\n\n", sqrt( a*a + b*b ));
        }
    }
    return 0;
}