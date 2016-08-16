#include <cstdio>
using namespace std;

int main(){
    int n, f; scanf("%d%d",&n,&f);
    n = n/100 * 100;
    if ( n % f == 0 ){
        printf("00");
        return 0;
    }
    int ans = (n + f - n % f)%100;
    if( ans < 10 ) printf("0");
    printf("%d",ans);
    return 0;
}