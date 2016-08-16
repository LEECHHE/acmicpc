#include <cstdio>
#include <algorithm>
using namespace std;
int n,l,w,h;
bool check(long double m){
    return n <= (long long)(l/m)*(long long)(w/m)*(long long)(h/m);
}
int main(){
    scanf("%d%d%d%d",&n,&l,&w,&h);
    long double start = 0, end = 1000000000;
    while (end-start > 1e-10){
        long double mid = (start+end)/2;
        if( check(mid) ){
            start = mid;
        }
        else{
            end = mid;
        }
    }
    printf("%.10Lf",start);
    return 0;
}