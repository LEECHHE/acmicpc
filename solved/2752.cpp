#include <cstdio>
using namespace std;

void swap( int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int A, B, C;
    scanf("%d %d", &A, &B);
    if ( A > B ) swap(A, B);
    scanf("%d", &C);
    if ( B > C ){
        if( A > C){
            swap( A, C);
            swap( B, C);
        }
        else
            swap(B, C);
    }
    printf("%d %d %d", A, B, C );
    return 0;
}