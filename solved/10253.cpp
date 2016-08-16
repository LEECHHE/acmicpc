#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
//const int INF = 987654321;
int gcd(int _a, int _b){
    int a = _a;
    int b = _b;
    while( b > 0 ){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d%d",&a,&b);
        int i = 1;
        while(1){
            if( a == 1 ) break;
            for( ;a * i - b < 1; ++i);
            a = a*i-b;
            b *= i;

            while(1){
                int g = gcd(a,b);
                if( g == 1 ) break;
                a /= g;
                b /= g;
            }
        }
        printf("%d\n", b);
    }
    return 0;
}