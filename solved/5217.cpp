#include <cstdio>

int main(){
    int N; scanf("%d", &N);
    for ( int i  = 0 ; i < N ; ++i ){
        int input; scanf("%d", &input);
        printf("Pairs for %d: ", input);
        int j = 1;
        for ( ; j < (input+1)/2-1; ++j ){
            printf("%d %d, ", j, input-j);
        }
        if ( j < (input+1)/2 ) printf("%d %d", j, input-j);
        printf("\n");
    }
    return 0;
}