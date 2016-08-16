#include <cstdio>
using namespace std;
int main(){
    int N,m,M,T,R;
    scanf("%d%d%d%d%d",&N,&m,&M,&T,&R);
    int ret = -1;
    if( m+T <= M ){
        ret = 0;
        int cur = m;
        while (N > 0) {
            while (cur+T <= M && N > 0) {
                ++ret;
                --N;
                cur += T;
            }
            while (N > 0 && cur+T > M) {
                ++ret;
                cur -= R;
                if( cur < m ){
                    cur = m;
                    break;
                }
            }
        }
    }
    printf("%d",ret);
    return 0;
}