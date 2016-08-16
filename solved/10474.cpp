#include <cstdio>
using namespace std;
int main(){
    while (1) {
        int a,b; scanf("%d%d",&a,&b);
        if( a == 0 && b == 0 ) break;
        printf("%d %d / %d\n",a/b,a%b,b);
    }
    return 0;
}