#include <cstdio>
using namespace std;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}
int main(){
    int x[4],y[4];
    for( int i = 0 ; i < 4 ; ++i ){
        scanf("%d%d",&x[i],&y[i]);
    }
    printf("%d",ccw(x[0],y[0],x[1],y[1],x[2],y[2])*ccw(x[0],y[0],x[1],y[1],x[3],y[3]) == -1);
    return 0;
}