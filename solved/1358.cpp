#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int w,h,p,q,n;
double r;
double e = 1e-7;
bool in( int x, int y ){
    if( y < q || y > q+h) return false;
    if( x < p-(double)h/2 || x > p+w+(double)h/2 ) return false;
    
    if( x < p ) return pow(x-p,2)+pow(y-q-r,2)-pow(r,2)<= e;
    else if( x > p+w ) return pow(x-p-w,2)+pow(y-q-r,2)-pow(r,2)<=e;
    else return true;
}
int main(){
    scanf("%d%d%d%d%d",&w,&h,&p,&q,&n);
    r = (double)h/2;
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int x,y; scanf("%d%d",&x,&y);
        if( in(x,y)) ++ret;
    }
    printf("%d",ret);
    return 0;
}