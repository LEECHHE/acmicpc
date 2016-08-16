#include <cstdio>
using namespace std;

// 1 2  3 3 4 4  5 5 5 6 6 6  7 7 7 7 .....
int main()
{
    int T;
    long long x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld", &x, &y);
        long long len;
        long long n = 1;
        
        for( len = y - x; len > n * ( n + 1 ) ; n++);
        long long index_in_group = len - n * ( n-1 );
        if ( index_in_group <= n )
            printf( "%lld\n", 2*n-1 );
        else
            printf( "%lld\n", 2*n );
    }
    return 0;
}