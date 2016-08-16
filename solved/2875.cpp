#include <cstdio>
using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    int remainW = 0, remainM = 0, count = 0;
    if( n >= 2*m ) count = m;
    else count = n/2;
    remainW = n - 2 * count;
    remainM = m - count;
    
    k -= remainM + remainW;
    while( k > 0 ){
        k -= 3;
        count--;
    }
    printf("%d", count);
    return 0;
}