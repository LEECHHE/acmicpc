#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mat[1000][1000];
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j )
            scanf("%lld",&mat[i][j]);
    }
    if( n == 2 ){
        printf("1 1");
        return 0;
    }
    ll ret[1000];
    for( int i = 1 ; i < n-1 ; ++i ){
        ret[i] = (mat[0][i]-mat[0][i+1]+mat[i][i+1])/2;
    }
    ret[0] = mat[0][1]-ret[1];
    ret[n-1] = mat[n-2][n-1]-ret[n-2];
    for( int i = 0 ; i < n ; ++i ){
        printf("%lld ",ret[i]);
    }
    return 0;
}