#include <cstdio>
using namespace std;

int main () {
    int N = 0;
    int MAX = 0;
    for ( int i = 0 ; i < 10 ; ++i ){
        int in, out;
        scanf( "%d %d" , &out, &in );
        N += ( in - out );
        if ( MAX < N )
            MAX = N;
    }
    printf( "%d", MAX );
    return 0;
}