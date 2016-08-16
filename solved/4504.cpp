#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    while(1){
        int t; scanf("%d",&t);
        if(t==0) break;
        printf("%d is ",t);
        if( t % n ){
            printf("NOT ");
        }
        printf("a multiple of %d.\n",n);
    }
    return 0;
}