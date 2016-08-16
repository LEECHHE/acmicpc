#include <cstdio>
using namespace std;
int gcd(int a, int b){
    int t;
    if( a < b ){
        t = a; a = b; b = t;
    }
    while(b){
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int n,r1; scanf("%d%d",&n,&r1);
    while(--n){
        int r; scanf("%d",&r);
        int cd = gcd(r1, r);
        printf("%d/%d\n",r1/cd,r/cd);
    }
    return 0;
}