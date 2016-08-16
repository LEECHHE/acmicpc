#include <cstdio>
using namespace std;

int main(){
    int max = -1;
    int x, y;
    for ( int i = 0 ; i < 81 ; i++ ){
        int temp;
        scanf("%d", &temp);
        if ( temp > max ){
            max = temp;
            x = i / 9;
            y = i % 9;
        }
    }
    printf("%d\n%d %d", max, x+1, y+1 );
    return 0;
}