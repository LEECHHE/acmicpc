#include <cstdio>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int cur = 0;
        for( int i = 0 ; i < 6 ; ++i ){
            int v; scanf("%d",&v);
            cur += v;
        }
        int ret = 1;
        while(cur <= n){
            cur *= 4;
            ++ret;
        }
        printf("%d\n",ret);
    }
    return 0;
}