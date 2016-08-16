#include <cstdio>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    double ret = 0.0;
    double bx, by; scanf("%lf%lf",&bx,&by);
    double fx =bx, fy = by;
    for( int i = 1 ; i < n ; ++i ){
        double x, y; scanf("%lf%lf",&x,&y);
        ret += bx*y-x*by;
        bx = x, by = y;
    }
    ret += bx*fy-fx*by;
    if (ret < 0) ret *= -1;
    printf("%.1lf", ret/2);
    return 0;
}