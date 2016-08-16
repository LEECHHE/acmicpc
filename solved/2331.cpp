#include <cstdio>
using namespace std;
int has[1000000]= {0};
int a,p;
int pow(int n, int k){
    int ret =1;
    for( int i = 0 ; i < k ; ++i ){
        ret *= n;
    }
    return ret;
}
int iter(int n){
    int ret = 0;
    while (n>=10) {
        ret += pow(n%10,p);
        n /= 10;
    }
    return ret + pow(n, p);
}
int main(){
    scanf("%d%d",&a,&p);
    ++has[a];
    while (1) {
        a = iter(a);
        if(++has[a] == 3) break;
    }
    int ret = 0;
    for( int i = 0 ; i < 1000000 ; ++i )
        if (has[i] == 1) ++ret;
    printf("%d",ret);
    return 0;
}