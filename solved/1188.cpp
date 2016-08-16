#include <iostream>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    n %= m;
    if( n == 0 ) printf("0");
    else{
        int len = m*n;
        int ret = 0;
        for( int p = n ; p <= len ; p += n ){
            if( p % m ) ++ret;
        }
        printf("%d",ret);
    }
    return 0;
}