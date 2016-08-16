#include <cstdio>
using namespace std;
int main(){
    int n,m;
    int a[10000];
    int sum[10000] = { 0 };
    scanf("%d%d",&n,&m);
    scanf("%d",&a[0]);
    sum[0] = a[0];
    for( int i = 1 ; i < n ;++i){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    int ans = 0;
    for ( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j <= i ; ++j ){
            if( m == sum[i] - sum[j] + a[j]) ++ans;
        }
    }
    printf("%d", ans);
    return 0;
}