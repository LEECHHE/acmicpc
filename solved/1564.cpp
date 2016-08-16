#include <cstdio>
using namespace std;

int main () {
    int N;
    scanf("%d", &N);
    unsigned long long factorial_5 = 1;
    for ( int i = 1 ; i <= N ; i++ ){
        unsigned long long temp_i = i;
        while( (temp_i % 10) == 0 ){
            temp_i /= 10;
        }
        factorial_5 = ( factorial_5 * (temp_i % 100000000000) ) % 100000000000;
        while( (factorial_5 % 10) == 0 )
            factorial_5 /= 10;
    }
    printf("%llu", factorial_5 % 100000);
    return 0;
}