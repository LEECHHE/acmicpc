#include <cstdio>
#include <vector>
using namespace std;
vector<int> primes;
void erathos(){
    vector<bool> isPrime(5000000, true);
    for( int i = 2 ; i < 5000000 ; ++i ){
        if( isPrime[i] ){
            primes.push_back(i);
            for( int j = i*2 ; j < 5000000; j += i ){
                isPrime[j] = false;
            }
        }
    }
}
int main(){
    erathos();
    int target; scanf("%d",&target);
    int ret = 0;

    if( target == 2 ) {
        ret = 1;
    }
    else{
        int cur = 0;
        int head = 0;
        int idx = 0;
        while(1){
            while( cur > target ){
                cur -= primes[head++];
            }
            if( cur == target ) ++ret;
            cur += primes[idx++];
            if( head >= idx ) break;
            if( primes[idx-1] > target ) break;
        }
    }
    printf("%d", ret);
    return 0;
}