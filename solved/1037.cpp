#include <cstdio>
#include <cstdlib>
using namespace std;

int compare ( const void *a, const void *b){
    return (*(int *)a) < (*(int *) b);
}
int main(){
    int N;
    int input[50];
    
    scanf( "%d", &N );
    for ( int i = 0 ; i < N ; i++ ){
        scanf( "%d", &input[i] );
    }
    qsort( input, N, sizeof(int), compare);
    
    printf("%ld", (long)input[0] * (long)input[N-1] );
    return 0;
}