#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int x,y; scanf("%d%d",&x,&y);
    if( x < y ){
        int temp = x;
        x = y;
        y = temp;
    }
    int gc = gcd(x,y);
    x /= gc; y /= gc;
    printf("%d", (x+y-1)*gc);
    return 0;
}