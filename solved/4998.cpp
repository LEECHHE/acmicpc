#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    double n; double b,m;
    while (scanf("%lf",&n) != -1) {
        scanf("%lf%lf",&b,&m);
        printf("%d\n",(int)ceil(log(m/n)/log(1+b*0.01)));
    }
    return 0;
}