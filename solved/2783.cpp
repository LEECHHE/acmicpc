#include <cstdio>
using namespace std;
int main(){
    int x,y; scanf("%d%d",&x,&y);
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        if( x*b > y*a) {
            x = a;
            y = b;
        }
    }
    printf("%.3lf", (double)x/y*1000);
    return 0;
}