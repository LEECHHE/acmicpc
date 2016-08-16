#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int base[100001] = { 0 };
int main(){
    base[1] =1;
    for( int i = 2 ; i <= 100000 ; ++i ){
        if( base[i] == 0 ){
            base[i] = i;
            for (long long j = (long long)i*i; j <= 100000; j += i) {
                if( base[j] == 0 )
                    base[j] = i;
            }
        }
    }
    int n,k; scanf("%d%d",&n,&k);
    int ret = n > k ? k : n;
    for( int i = k+1 ; i <= n ; ++i ){
        int cur = i;
        while (base[cur] != cur ) {
            cur /= base[cur];
        }
        if( base[cur] <= k ) ++ret;
    }
    printf("%d",ret);
    return 0;
}