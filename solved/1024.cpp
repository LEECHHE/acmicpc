#include <cstdio>
using namespace std;

int main(){
    int n,l; scanf("%d%d", &n,&l);
    int a = -1;
    while(1){
        int head = 2*n+l-l*l;
        if( head % (2*l) == 0 ){
            a = head / (2*l);
            break;
        }
        ++l;
        if(l>100) break;
    }
    if( a < 0 ) printf("-1");
    else{
        for( int i = 0 ; i < l ; ++i ){
            printf("%d ",a+i);
        }
    }
    return 0;
}