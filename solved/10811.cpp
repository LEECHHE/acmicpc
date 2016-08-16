#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int basket[101] = { 0 };
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 1 ; i <= n ; ++i ) basket[i] = i;
    while(m--){
        int a,b; scanf("%d%d",&a,&b);
        reverse(basket+a, basket+b+1);
    }
    for( int i = 1 ; i <= n ; ++i ){
        printf("%d ",basket[i]);
    }
    return 0;
}