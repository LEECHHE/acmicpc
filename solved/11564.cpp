#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    ll ret = 0;
    if( (a >= 0 && b >= 0) || (a <= 0 && b <= 0) ){
        if( b <= 0 ) {
            a *= -1; b *= -1;
            ll t = a;
            a = b;
            b = t;
        }
        ret = b/k - a/k;
        ret += a%k == 0;
    }
    else{
        ret = b/k - a/k + 1;
    }
    printf("%lld",ret);
    return 0;
}