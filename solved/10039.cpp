#include <cstdio>
using namespace std;

int main(){
    int sum = 0;
    for ( int i = 0 ; i < 5 ; i++ ){
        int temp;
        scanf("%d", &temp);
        if ( temp < 40 ) sum += 40;
        else sum += temp;
    }
    printf("%d", sum / 5 );
    return 0;
}