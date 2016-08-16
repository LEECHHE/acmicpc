#include <cstdio>
using namespace std;
int main(){
    int fib[41] = {1,1,2};
    for( int i = 3 ; i <= 40 ; ++i ){
        fib[i] = fib[i-1]+fib[i-2];
    }
    int n,m; scanf("%d%d",&n,&m);
    int ret = 1;
    if( m == 0 ){
        ret = fib[n];
    }
    else{
        int vip,prev = 0;
        for( int i = 0 ; i < m ; ++i ){
            scanf("%d", &vip);
            ret *= fib[vip-prev-1];
            prev = vip;
        }
        ret *= fib[n-prev];
    }
    printf("%d", ret);
    return 0;
}