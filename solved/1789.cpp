#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    unsigned long long S, N;
    scanf( "%llu", &S );
    
    N = (unsigned long long)( 0.5 + sqrt( 1 + 8 * S ) / 2 );
    while(--N){
        if( S - ( N * ( N + 1 ) / 2 ) >= N )
            break;
    }
    printf("%llu" , N + 1 );
    return 0;
}