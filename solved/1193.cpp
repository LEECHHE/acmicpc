#include <cstdio>
using namespace std;
int main(){
    int x; scanf("%d",&x);
    int g = 1;
    while( g*(g+1) / 2 < x ) ++g;
    x -= g*(g-1)/2;

    int ja = g % 2 ? g+1-x : x;
    int mo = g+1-ja;
    printf("%d/%d",ja,mo);
    return 0;
}