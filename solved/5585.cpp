#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    n = 1000-n;
    int ret =0;
    for( int i = 0 ; i < 6 ; ++i ){
        ret += n/coin[i];
        n %= coin[i];
    }
    
    printf("%d", ret);
    return 0;
}