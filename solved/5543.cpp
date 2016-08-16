#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int burger = 2000;
    for ( int i = 0 ; i < 3 ; i++ ){
        int temp;
        scanf("%d", &temp);
        if ( temp < burger )
            burger = temp;
    }
    int drink = 2000;
    for ( int i = 0 ; i < 2 ; i++ ){
        int temp;
        scanf("%d", &temp);
        if ( temp < drink )
            drink = temp;
    }
    printf("%d", burger + drink - 50 );
    return 0;
}