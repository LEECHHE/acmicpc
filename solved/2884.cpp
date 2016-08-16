#include <cstdio>
using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    if ( (b-=45) < 0){
        b += 60;
        a--;
    }
    if ( a < 0 ){
        a += 24;
    }
    printf("%d %d", a, b);
    return 0;
}