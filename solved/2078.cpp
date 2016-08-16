#include <cstdio>
using namespace std;
int main(){
    int a,b; scanf("%d%d",&a,&b);
    int l = 0,r = 0;
    while(a != b){
        if( a > b ){
            a -= b;
            ++l;
        }
        else{
            b -= a;
            ++r;
        }
        if( a == 1 ){
            r += b-1;
            break;
        }
        else if( b == 1 ){
            l += a-1;
            break;
        }
    }
    printf("%d %d", l,r);
    return 0;
}