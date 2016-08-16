#include <cstdio>
using namespace std;
int base[100001] = { 0 };
bool underprime(int n){
    int ret = 0;
    while (n>1) {
        n /= base[n];
        ++ret;
    }
    return base[ret] == ret;
}
int main(){
    base[1] = 0;
    for( int i = 2 ; i <= 100000 ; ++i ){
        if( base[i] == 0 ){
            base[i] = i;
            for( long long j = (long long)i*i ; j <= 100000 ; j += i){
                if(base[j] == 0 ) base[j] = i;
            }
        }
    }
    int a,b; scanf("%d%d",&a,&b);
    int ret = 0;
    for( int i = a ; i <= b ; ++i ){
        if(underprime(i)) ++ret;
    }
    printf("%d",ret);
    return 0;
}