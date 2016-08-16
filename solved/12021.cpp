#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    double x,y; scanf("%lf%lf",&x,&y);
    
    while(1){
        double bx = (x+y)/2;
        double by = x*y/bx;
        if( bx-x <= 0.0000000001 && by-y <= 0.0000000001){
            x = bx, y = by;
            break;
        }
        x = bx, y = by;
    }
    printf("%.3lf %.3lf", x,y );
    
    return 0;
}