#include <cstdio>
using namespace std;
typedef long long ll;
bool chk[1000001] = { false };
int main(){
    ll a,b,k; scanf("%lld%lld",&a,&b);
    int ret =0;
    for( ll i = 2 ; ; i++ ){
        k = i*i;
        if( k > b ) break;
        ll j = a/k;
        if( j*k < a ) ++j;
        for (; ; ++j) {
            if( j*k > b ) break;
            if( chk[j*k-a] ) continue;
            chk[j*k-a] = 1;
            ++ret;
        }
    }
    printf("%lld",(b-a+1)-ret);
    return 0;
}