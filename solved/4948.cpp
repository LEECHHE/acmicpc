#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> primes;
    bool isprime[123456*2+1]; memset(isprime,true,sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for( int i = 2 ; i <= 123456*2 ; ++i ){
        if( !isprime[i] ) continue;
        primes.push_back(i);
        for( long long j = (long long)i*i ; j <= 123456*2 ; j += i )
            isprime[j] = false;
    }
    while(1){
        int n; scanf("%d",&n);
        if( n == 0 ) break;
        auto up = lower_bound(primes.begin(), primes.end(), 2*n);
        auto bottom = lower_bound(primes.begin(), primes.end(), n);
        printf("%ld\n", up-bottom+(isprime[2*n])-isprime[n]);
//        while(bottom != up ){
//            printf("%d ",*bottom);
//            ++bottom;
//        }
    }
    return 0;
}