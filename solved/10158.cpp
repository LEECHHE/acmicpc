#include <cstdio>
using namespace std;
int main(){
    int w,h,p,q,t; scanf("%d%d%d%d%d",&w,&h,&p,&q,&t);
    p += t, q += t;
    p %= 2*w, q %= 2*h;
    if ( p > w ){
        p = w-p%w;
    }
    if( q > h ){
        q = h-q%h;
    }
    printf("%d %d", p,q);
    return 0;
}