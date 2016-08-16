#include <cstdio>
#include <cstdlib>
using namespace std;

int ascend(const void* a, const void *b ){
    return (*(int*)a) < (*(int*)b);
}

int descend( const void *a, const void *b ){
    return (*(int*)a) > (*(int*)b);
}
int main(){
    int A[50]; int B[50];
    int N;
    
    scanf("%d", &N);
    for( int i = 0 ; i < N ; i++ ) scanf("%d", &A[i]);
    for( int i = 0 ; i < N ; i++ ) scanf("%d", &B[i]);
    
    qsort( A, N, sizeof(int), ascend );
    qsort( B, N, sizeof(int), descend );
    
    int result;
    for ( int i = 0 ; i < N ; i++ )
        result += (A[i] * B[i]);
    
    printf("%d", result);
    return 0;

}