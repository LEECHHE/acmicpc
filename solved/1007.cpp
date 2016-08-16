#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> intPair;
bool selected[20] = { false };
intPair v[20];
int n;
double ret;
void dfs(int cur, int sz){
    if( sz == n/2 ){
        double x = 0.0, y = 0.0;
        for( int i = 0 ; i < n ; ++i ){
            int sign = selected[i] ? 1 : -1;
            x += sign*v[i].first;
            y += sign*v[i].second;
        }
        ret = min(ret, sqrt(x*x+y*y));
        return;
    }
    for( int i = cur+1 ; i < n ; ++i ){
        if( sz >= n/2 ) break;
        if( selected[i] ) continue;
        selected[i] = true;
        dfs(i, sz+1);
        selected[i] = false;
    }
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        memset(selected, 0, sizeof(selected));

        ret = 987654321;
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d%d",&v[i].first,&v[i].second);
        }
        for( int i = 0 ; i <= n/2 ; ++i ){
            selected[i] = true;
            dfs(i,1);
            selected[i] = false;
        }
        printf("%.6lf\n", ret);
    }
    return 0;
}