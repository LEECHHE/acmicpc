#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cmath>
using namespace std;
vector<int> primes;
bool notPrime[10000001]={false};
//const long long LIMIT = 100000000000000L;
int main(){
    for( int i = 2 ; i <= 10000000 ; ++i ){
        if( !notPrime[i] ){
            primes.push_back(i);
            for( int j = i*2 ; j <= 10000000; j += i ){
                notPrime[j] = true;
            }
        }
    }
//    sort(primes.begin(), primes.end());
//    for( auto p : primes ) printf("%lld\n",p);
    double a,b; scanf("%lf%lf",&a,&b);
    int ret = 0;
    double cur;
    for( auto p : primes ){
        cur = (double)p*p;
        if( cur > b ) break;
        while (cur < a) {
            cur *= p;
        }
        while (cur <= b) {
            cur *= p;
            ++ret;
        }
    }
    printf("%d", ret);
//    printf("%ld",(upper_bound(primes.begin(), primes.end(), b)-lower_bound(primes.begin(), primes.end(), a)));
    return 0;
}