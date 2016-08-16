#include <cstdio>
using namespace std;

int fact( int n ){
    if ( n == 1 ) return 1;
    else return n * fact(n-1);
}
int main(){
    while(1){
        int n;
        scanf("%d", &n);
        if ( !n ) break;
        else{
            int fac = 1;
            int result = 0;
            while ( n ){
                result += (n % 10) * fact ( fac++ );
                n /= 10;
            }
            printf("%d\n", result );
        }
    }
}