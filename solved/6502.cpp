#include <cstdio>
using namespace std;
int r,w,l;
int main(){
    int cse = 1;
    while(1){
        scanf("%d",&r);
        if( r == 0 ) break;
        scanf("%d%d", &w,&l);
        printf("Pizza %d ",cse++);
        
        if( w*w + l*l <= 4 * r * r ) printf("fits on the table.\n");
        else printf("does not fit on the table.\n");
    }
    return 0;
}