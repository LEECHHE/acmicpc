#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    int N, K;
    scanf( "%d %d", &N, &K );
    int cur = 1;
    for ( int i = 0 ; i < K ; ++i ){
        if ( cur > N ){
            cur = 1;
            break;
        }
        while( N % cur++ );
    }
    printf( "%d", cur - 1 );
    return 0;
}