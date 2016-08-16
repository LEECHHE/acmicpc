#include <cstdio>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    char s[1000001]; scanf("%s", s);
    int idx = 0;
    int cnt = 0;
    int ret = 0;
    while (idx < m) {
        while (idx < m && s[idx] == 'O') ++idx;
        if (idx >= m-1) break;
        for ( ++idx ; idx < m-1 ; idx += 2 ) {
            if( s[idx] == 'O' && s[idx+1] == 'I') ++cnt;
            else{
                break;
            }
            if( cnt >= n ){
                ret++;
            }
        }
        cnt = 0;
    }
    printf("%d", ret);
    return 0;
}