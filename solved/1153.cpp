#include <cstdio>
#include <vector>
using namespace std;
vector<int> primes;
bool notPrime[1000000];
int main(){
    for( int i = 2 ; i < 1000000 ; ++i ){
        if( !notPrime[i] ){
            primes.push_back(i);
            for( long long j = (long long)i*i ; j < 1000000 ; j +=i ){
                notPrime[j] = true;
            }
        }
    }
    int n; scanf("%d",&n);
    vector<int> ans;
    if( n >= 8 ){
        ans.push_back(2);
        if( n % 2 ){
            n -= 5;
            ans.push_back(3);
        }
        else{
            n -= 4;
            ans.push_back(2);
        }
        for( auto p : primes ){
            if( !notPrime[n-p] ){
                ans.push_back(p);
                ans.push_back(n-p);
                break;
            }
        }
    }
    if (ans.size() != 4) {
        ans.clear(); ans.push_back(-1);
    }
    for( auto a : ans ){
        printf("%d ", a);
    }
    return 0;
}