#include <cstdio>
using namespace std;

int main () {
    int T;
    scanf( "%d", &T );
    
    while(T--){
        unsigned long long s; int n;
        scanf ("%lld %d", &s, &n );
        while ( n-- ){
            int q, p;
            scanf("%d %d", &q, &p);
            s += q * p;
        }
        printf("%lld\n", s);
    }
    return 0;
}