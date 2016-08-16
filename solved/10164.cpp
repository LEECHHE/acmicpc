#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[16][16];
int n,m,k;
int solve(int x, int y){
    if( x < 0 || y < 0 ) return 0;
    if (x == 0 && y == 0) {
        return 1;
    }
    int& ret = cache[x][y];
    if( ret != -1 ) return ret;
    return ret = solve(x-1, y)+solve(x, y-1);
}
int main(){
    memset(cache, -1, sizeof(cache));
    scanf("%d%d%d",&n,&m,&k);
    int x = (k-1)/m, y = (k-1)%m;
    printf("%d",k==0?solve(n-1, m-1) :solve(n-x-1, m-y-1)*solve(x, y) );
    return 0;
}