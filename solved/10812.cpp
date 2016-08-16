#include <cstdio>
using namespace std;
int basket[2][101];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for( int i = 1 ; i <= n ; ++i ) basket[0][i] = i;
    for( int i = 0 ; i < k ; ++i ){
        int b,m,e; scanf("%d%d%d",&b,&e,&m);
        for( int j = 1 ; j < b ; ++j ) basket[(i+1)%2][j] = basket[i%2][j];
        for( int j = e+1 ; j <=n ; ++j ) basket[(i+1)%2][j] = basket[i%2][j];
        
        for( int j = m ; j <= e ; ++j ){
            basket[(i+1)%2][b+j-m] = basket[i%2][j];
        }
        int base = b+e-m+1;
        for (int j = b; j < m ; ++j ) {
            basket[(i+1)%2][base+j-b] = basket[i%2][j];
        }
    }
    for( int i = 1 ; i <= n ; ++i )printf("%d ",basket[k%2][i]);
    return 0;
}