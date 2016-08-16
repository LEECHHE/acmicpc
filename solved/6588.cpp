#include <cstdio>
#include <vector>
using namespace std;
vector<int> primes;
bool notPrime[1000000];
int main(){
    for( int i = 2 ; i < 1000000 ; ++i ){
        if(!notPrime[i]){
            primes.push_back(i);
            for( long long j = (long long)i*i ; j < 1000000 ; j += i ){
                notPrime[j] = true;
            }
        }
    }
    while (1) {
        int n; scanf("%d",&n);
        if( n == 0 ) break;
        printf("%d = ", n);
        for( auto p : primes ){
            if( !notPrime[n-p] ){
                printf("%d + %d\n",p,n-p);
                break;
            }
        }
    }
    return 0;
}