#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int seq[100000];
    bool contain[1000001] = { 0 };
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
        contain[seq[i]] = true;
    }
    int x; scanf("%d",&x);
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int t = x-seq[i];
        if( t <= 0 || t > 1000000 || seq[i] == t ) continue;
        if( contain[t]){
            ++ret;
            contain[seq[i]] = contain[t] = false;
        }
    }
    printf("%d",ret);
    return 0;
}