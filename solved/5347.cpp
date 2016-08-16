#include <cstdio>
using namespace std;

long long gcd ( long long a, long long b ){
    long long t;
    while ( b > 0 ){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a * b / gcd( a, b) );
    }
    return 0;
}