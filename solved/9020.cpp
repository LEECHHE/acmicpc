#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> primes;
bool notPrime[10001];
int main(){
    for( int i = 2 ; i <= 10000 ; ++i ){
        if(!notPrime[i]){
            primes.push_back(i);
            for( int j = i*i ; j <= 10000 ; j += i ){
                notPrime[j] = true;
            }
        }
    }
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        if( n == 0 ) break;
        int idx =(int)(lower_bound(primes.begin(), primes.end(), n/2)-primes.begin());
        while(idx>=0){
            int a = primes[idx];
            int b = n-a;
            if( !notPrime[b] ){
                if( a > b ) swap(a, b);
                printf("%d %d\n",a,b);
                break;
            }
            --idx;
        }
    }
    return 0;
}