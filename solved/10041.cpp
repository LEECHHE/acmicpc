#include <cstdio>
#include <algorithm>
using namespace std;
int abs(int a){
    return a<0?-a:a;
}
int main(){
    int w,h,n; scanf("%d%d%d",&w,&h,&n);
    int x,y; scanf("%d%d",&x,&y);
    int ret = 0;
    for( int i = 1 ; i < n ; ++i ){
        int cx, cy; scanf("%d%d",&cx,&cy);
        if( (cx >= x && cy >= y) || (cx <=x && cy <= y )){
            int step = min(abs(cx-x),abs(cy-y));
            ret += step;
            if( cx >= x )
                x += step, y += step;
            else
                x -= step, y -= step;
            
            if( cx == x ) ret += abs(cy-y);
            else ret += abs(cx-x);
        }
        else{
            ret += abs(cx-x) + abs(cy-y);

        }
        x = cx, y = cy;
    }
    printf("%d\n",ret);
    return 0;
}