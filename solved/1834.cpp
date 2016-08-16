#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    unsigned long long sum = 0;
    for ( int i = 1 ; i < n ; ++i )
        sum += i*n+i;

    printf("%lld", sum);
    return 0;
}