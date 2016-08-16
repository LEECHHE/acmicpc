#include <cstdio>
using namespace std;
int sum[100001] = { 0 };
int main(){
    int n,m; scanf("%d%d",&n,&m);
    scanf("%d",&sum[1]);
    for( int i = 2 ; i <= n ; ++i ){
        int t; scanf("%d",&t);
        sum[i] = sum[i-1]+t;
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        printf("%d\n", sum[b]-sum[a-1]);
    }
    return 0;
}