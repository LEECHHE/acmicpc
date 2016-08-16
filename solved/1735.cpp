#include <cstdio>
using namespace std;

int gcd( int a_, int b_ ){
    int t;
    int a = a_;
    int b = b_;
    while( b > 0 ){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main () {
    int n1[2];
    int n2[2];
    scanf("%d %d", &n1[0], &n1[1] );
    scanf("%d %d", &n2[0], &n2[1] );
    int result[2];
    result[0] = n1[0] * n2[1] + n1[1] * n2[0] ;
    result[1] = n1[1] * n2[1];
    
    int gcdd = gcd( result[0], result[1] );
    
    printf("%d %d", result[0] / gcdd , result[1] / gcdd);
    return 0;
}