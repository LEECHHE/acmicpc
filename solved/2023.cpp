#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int n;
bool notPrime[10001] = { false };
vector<int> prime;
bool isPrime(int n){
    if( n <= 10000 ) return !notPrime[n];
    int limit = sqrt(n);
    for ( auto p : prime ){
        if( p > limit ) break;
        if( n%p == 0) return false;
    }
    return true;
}
void wonder(int step, int num){
    if( step == n ){
        printf("%d\n",num);
        return;
    }
    for( int i = 0 ; i < 10 ; ++i ){
        if( isPrime(num*10+i)){
            wonder(step+1, num*10+i);
        }
    }
}
int main(){
    notPrime[0] = notPrime[1] = true;
    for (int i = 2 ; i <= 10000; ++i ) {
        if(!notPrime[i]){
            prime.push_back(i);
            for( long long j = (long long)i*i ; j <= 10000 ; j += i ){
                notPrime[j] = true;
            }
        }
    }
    scanf("%d",&n);
    wonder(1, 2);
    wonder(1, 3);
    wonder(1, 5);
    wonder(1, 7);
    return 0;
}