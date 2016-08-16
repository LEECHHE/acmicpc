#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double n; scanf("%lf", &n);
    int k = 0;
    while( n > pow(10,k)){
        n /= pow(10,k);
        n = round(n)*pow(10,k);
        ++k;
    }
    printf("%.lf",n);
    return 0;
}