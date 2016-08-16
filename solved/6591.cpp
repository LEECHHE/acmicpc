#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    while (1) {
        int n,r; scanf("%d%d",&n,&r);
        if( n == 0 && r == 0 ) break;
        r = min(r, n-r);
        ll dividend = 1;
        int k = r;
        for( int i = 0 ; i < r ; ++i ){
            dividend *= n-i;
            while (k > 0 && dividend%k == 0) {
                dividend /= k;
                --k;
            }
        }
        printf("%lld\n",dividend);
    }
    return 0;
}