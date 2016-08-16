#include <cstdio>
#include <cstdlib>
using namespace std;

int compare ( const void* a, const void* b){
    return (*(int*)a) > (*(int*)b);
}
int main(){
    int L;
    int input[50];
    scanf("%d", &L);
    
    for ( int i = 0 ; i < L ; i++ ){
        scanf("%d", &input[i]);
    }
    qsort( input, L, sizeof(int), compare);
    int left = -1;
    int right = -1;
    int N;
    scanf("%d", &N);
    for ( int i = 0 ; i < L ; i++ ){
        if ( N == input[i] ){
            printf("0");
            return 0;
        }
        if ( N < input[i] ){
            right = input[i];
            if ( i > 0 )
                left = input[i-1];
            else
                left = 0;
            break;
        }
    }
    printf("%d", (N - left - 1) * ( right - N - 1) + ( N - left - 1 ) + ( right - N - 1) );
    return 0;
}