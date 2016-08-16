#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    if( a < b ) swap(a, b);
    while (b) {
        ll t = a%b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    ll a,b; scanf("%lld%lld",&a,&b);
    ll k = gcd(a, b);
    for( int i = 0 ; i < k ; ++i ){
        printf("1");
    }
    return 0;
}