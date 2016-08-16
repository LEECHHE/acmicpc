#include <cstdio>
#include <algorithm>
using namespace std;
int p[200000];
int n,c;
bool check(int v){
    int cnt = 1;
    int cur = p[0];
    for( int i = 1 ; i < n ; ++i ){
        if( p[i]-cur >= v ){
            ++cnt;
            cur = p[i];
        }
    }
    return cnt >= c;
}
int main(){
    scanf("%d%d",&n,&c);
    for (int i = 0 ; i < n; ++i) {
        scanf("%d",&p[i]);
    }
    sort(p, p+n);
    int l = 1, r = p[n-1]-p[0];
    int ret = 1;
    while (l<=r) {
        int m = (l+r)/2;
        if( check(m) ){
            if( ret < m ) ret = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    printf("%d",ret);
    return 0;
}