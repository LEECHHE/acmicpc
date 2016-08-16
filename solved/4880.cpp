#include <cstdio>
using namespace std;

int main(){
    while(1){
        int a1,a2,a3; scanf("%d%d%d",&a1,&a2,&a3);
        if(a1 == 0 && a2 == 0 && a3 == 0) break;
        if(a2-a1 == a3-a2 && a2-a1 != 0){
            printf("AP %d\n", a3+a3-a2);
        }
        else{
            printf("GP %d\n", a3*a3/a2);
        }
    }
    return 0;
}