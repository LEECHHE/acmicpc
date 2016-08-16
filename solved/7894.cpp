#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int m; scanf("%d",&m);
        double ret = 0;
        for( int i = 1 ; i <= m ; ++i ){
            ret += log10(i);
        }
        printf("%d\n", (int)floor(ret)+1);
    }
    return 0;
}