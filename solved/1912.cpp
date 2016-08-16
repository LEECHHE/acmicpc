#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int cur = 0;
    int ret = 1<<31;
    while(n--){
        int t; scanf("%d",&t);
        if( cur < 0 ) cur = t;
        else cur += t;
        ret = max( cur, ret);
    }
    printf("%d", ret);
    return 0;
}