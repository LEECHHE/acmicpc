#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int basket[101]; for( int i = 1 ; i <= n ; ++i) basket[i] = i;
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        swap(basket[a], basket[b]);
    }
    for( int i = 1 ; i <= n ; ++i ) printf("%d ", basket[i]);
    return 0;
}