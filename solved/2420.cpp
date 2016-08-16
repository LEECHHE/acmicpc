#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", abs(n-m));
    return 0;
}