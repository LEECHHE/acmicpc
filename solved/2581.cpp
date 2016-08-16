#include <cstdio>
using namespace std;

int main(){
    int M, N;
    scanf("%d\n%d", &M , &N);
    
    if( N == 1 ){
        printf("-1");
        return 0;
    }
    if ( M == 1 )
        M++;
    int sum = 0;
    int min = -1;
    bool first = true;
    for ( int i = M; i <= N ; i++ ){
        bool isPrime = true;
        for ( int j = 2; j < i / 2 + 1; j++ ){
            if ( i % j == 0 ){
                isPrime = false;
                break;
            }
        }
        if ( isPrime ){
            sum += i;
            if ( first ){
                min = i;
                first = false;
            }
        }
    }
    if ( sum == 0 )
        printf("-1");
    else
        printf("%d\n%d", sum, min);
    return 0;
}