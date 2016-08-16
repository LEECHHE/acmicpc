#include <cstdio>
#include <algorithm>
using namespace std;
int sugar[2][5001] = { 0 };
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i <= n ; ++i ){
        sugar[0][i] = sugar[1][i] =1000000;
    }
    sugar[0][3] = 1;
    sugar[1][5] = 1;
    
    for( int i = 6 ; i <= n ; ++i ){
        sugar[0][i] = min(sugar[0][i-3], sugar[1][i-3]) + 1;
        sugar[1][i] = min(sugar[0][i-5], sugar[1][i-5]) + 1;
    }
    int ret = min(sugar[0][n],sugar[1][n]);
    if( ret >= 1000000 ) ret = -1;
    printf("%d", ret);
    return 0;
}