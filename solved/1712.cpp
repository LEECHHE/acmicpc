#include <cstdio>
using namespace std;
int main(){
    long long a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
    long long ret = -2;
    if( b < c ){
        long long profit = c-b;
        ret = a/profit;
    }
    printf("%lld",ret+1);
    return 0;
}