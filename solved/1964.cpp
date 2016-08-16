#include <cstdio>
using namespace std;

int main()
{
    unsigned long long N;
    scanf("%llu", &N);
    
    printf("%llu", (( 3*N*N + 5*N )/2 + 1)  % 45678);
    return 0;
}