#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int x[3]; scanf("%d%d%d", &x[0], &x[1],&x[2]);
        sort(x, x+3);
        if( x[0]*x[1]*x[2] == 0 ) break;
        if( x[2] * x[2] == x[1] * x[1] + x[0] * x[0] ){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
    }
    return 0;
}