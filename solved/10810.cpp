#include <cstdio>
using namespace std;
int main(){
    int basket[101] = { 0 };
    int n,m; scanf("%d%d",&n,&m);
    while(m--){
        int i,j,k; scanf("%d%d%d",&i,&j,&k);
        for( int b = i ; b <= j ; ++b ){
            basket[b] = k;
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        printf("%d ",basket[i]);
    }
    return 0;
}