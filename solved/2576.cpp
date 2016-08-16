#include <cstdio>
using namespace std;
int main(){
    int sum = 0;
    int min = 100;
    for ( int i = 0 ; i < 7 ; i++ ) {
        int temp;
        scanf("%d", &temp);
        if ( temp % 2 ){
            sum += temp;
            if ( temp < min )
                min = temp;
        }
    }
    if ( !sum ) printf("-1");
    else printf("%d\n%d", sum, min );
    return 0;
}