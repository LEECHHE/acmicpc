#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        bool isOpened[101] = { false };
        memset(isOpened, 1, sizeof(isOpened));
        int n; scanf("%d",&n);
        for( int i = 2; i <= n ; ++i ){
            for ( int k = i ; k <= n ; k += i ){
                isOpened[k] = !isOpened[k];
            }
        }
        int ret = 0;
        for ( int i = 1 ; i <= n ; ++i ){
            if( isOpened[i] ) ++ret;
        }
        printf("%d\n", ret);
    }
    return 0;
}