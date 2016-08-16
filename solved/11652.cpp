#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll seq[1000000];
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ) scanf("%lld",&seq[i]);
    sort(seq, seq+n);
    int currentCount = 1;
    ll cur = seq[0];
    int maxCount = 1;
    ll maxValue = seq[0];
    for( int i = 1 ; i < n ; ++i ){
        if( seq[i] == seq[i-1] ){
            ++currentCount;
            if ( i == n-1 ){
                if( maxCount < currentCount ){
                    maxCount = currentCount;
                    maxValue = cur;
                }
            }
        }
        else{
            if( maxCount < currentCount ){
                maxCount = currentCount;
                maxValue = cur;
            }
            currentCount = 1;
            cur = seq[i];
        }
    }
    printf("%lld",maxValue);
    return 0;
}