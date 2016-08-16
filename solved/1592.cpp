#include <cstdio>
using namespace std;
int main(){
    int n,m,l; scanf("%d%d%d",&n,&m,&l);
    int cnt[1000] = { 0 };
    int ret = 0;
    int idx = 0;
    while(1){
        if(++cnt[idx] == m ){
            break;
        }
        if( cnt[idx]%2 ){
            idx += l;
            idx %= n;
        }
        else{
            idx -= l;
            if( idx < 0 ) idx += n;
        }
        ++ret;
    }
    printf("%d",ret);
    return 0;
}