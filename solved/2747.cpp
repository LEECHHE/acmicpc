#include <cstdio>
using namespace std;

int fib[45];
int main(){
    int N;
    scanf("%d", &N);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for ( int i = 2 ; i <= N ; i++ ){
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("%d", fib[N]);
    return 0;
}