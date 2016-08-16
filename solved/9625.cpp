#include <cstdio>
using namespace std;

int main()
{
    int K;
    scanf("%d", &K);
    unsigned long long a = 0, b = 1;
    for ( int i = 1 ; i < K ; ++i )
    {
        unsigned long long temp_a = a;
        a = b;
        b += temp_a;
    }
    printf("%llu %llu", a, b);
    return 0;
}