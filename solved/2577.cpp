#include <cstdio>
using namespace std;

int main(){
    int A, B, C;
    int num[10] = { 0 };
    scanf("%d %d %d", &A, &B, &C );
    A *= (B *= C );
    while ( A ){
        num[ A % 10 ]++;
        A /= 10;
    }
    for ( int i = 0 ; i < 10 ; i++ )
        printf("%d\n", num[i]);
    
    return 0;
}