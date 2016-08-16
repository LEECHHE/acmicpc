#include <cstdio>
#include <cmath>
using namespace std;
const double PI = 3.141592653589793;
double dist(double x1, double y1, double x2, double y2 ){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
double square(double a, double b, double c){
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
    double x1,y1,x2,y2,x3,y3;
    while (scanf("%lf",&x1) != -1) {
        scanf("%lf%lf%lf%lf%lf",&y1,&x2,&y2,&x3,&y3);
        double a = dist(x1, y1, x2, y2);
        double b = dist(x2, y2, x3, y3);
        double c = dist(x3, y3, x1, y1);
        double S = square(a, b, c);
        double r = (a*b*c)/(4*S);
        printf("%.2lf\n",2*r*PI);
    }
    return 0;
}