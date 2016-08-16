#include <cstdio>
using namespace std;

int main () {
    int T;
    scanf("%d", &T);
    while(T--){
        int divisor = 2;
        int count = 0;
        int num;
        scanf("%d", &num);
        while( num > 1 ){
            count = 0;
            while ( !(num % divisor) ){
                count++;
                num /= divisor;
            }
            if( count > 0 )
                printf("%d %d\n", divisor, count);
            divisor++;
        }
    }
    return 0;
}