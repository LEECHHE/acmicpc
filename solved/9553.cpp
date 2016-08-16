#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double,double> dPair;
double angle(int x, int y){
    return atan2(x,y)*180/M_PI;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        double ret = 0.0;
        for( int i = 0 ; i < n ; ++i ){
            int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            double a = abs(angle(x1,y1)-angle(x2,y2));
            if( a >= 180 ) a = 360-a;
            ret += a/360;
        }
        printf("%.5lf\n",ret);
    }
    return 0;
}