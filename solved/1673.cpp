#include <cstdio>
using namespace std;

int main(){
    int e,c;
    while(scanf("%d%d",&e,&c) != -1){
        int coupon = e;
        int ret = e;
        while(coupon/c){
            int additional = coupon / c;
            ret += additional;
            coupon %= c;
            coupon += additional;
        }
        printf("%d\n", ret);
    }
    return 0;
}