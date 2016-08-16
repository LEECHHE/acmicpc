#include <cstdio>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int ret = 0;
        int n; scanf("%d",&n);
        for (int b = 2; b <= n; ++b ) {
            int k = n;
            while (1) {
                if( k%b == 0 ){
                    ++ret;
                }else{
                    break;
                }
                k /= b;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}