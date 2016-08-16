#include <cstdio>
using namespace std;
int N;
int input[9];

unsigned long long getFraction( int i ){
    unsigned long long result = 1;
    for ( int j = 0 ; j < N ; j++ )
        result *= input[j];
    return result / input[i];
}
unsigned long long gcd( unsigned long long a_, unsigned long long b_ ){
    unsigned long long t;
    unsigned long long a = a_;
    unsigned long long b = b_;
    while( b > 0 ){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main() {
    scanf("%d", &N);
    unsigned long long sum = 0;
    for ( int i = 0 ; i < N ; i++ )
        scanf("%d", &input[i]);
    for ( int i = 0 ; i < N ; i++ ){
        sum += getFraction(i);
    }
    unsigned long long below = 1;
    for ( int i = 0 ; i < N ; i++ ){
        below *= input[i];
    }
    
    unsigned long long gc = gcd( sum, below );
    
    printf("%llu/%llu", (below / gc), (sum / gc));
    return 0;
}