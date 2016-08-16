#include <cstdio>
using namespace std;
//const int INF = 987654321;
int a,b,c;
unsigned long long exponential(int a, int n){
    if( n == 0 ) return 1;
    if( n % 2 ) return ((a % c) * (exponential(a, n - 1) % c)) % c;
    else{
        unsigned long long sqr = exponential(a, n/2) % c;
        return (sqr * sqr) % c;
    }
}
int main(){
    scanf("%d%d%d", &a, &b, &c);
    printf("%lld", exponential(a, b));
    return 0;
}