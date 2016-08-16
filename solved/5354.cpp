#include <cstdio>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        int N;
        scanf("%d", &N);
        
        if( N == 0 ){
            printf("\n");
            continue;
        }
        if (N == 1 ){
            printf("#\n\n");
            continue;
        }
        if (N == 2){
            printf("##\n##\n\n");
            continue;
        }
        int j = N-2;
        for( int i = 0; i < N ; i++ ) printf("#");
        printf("\n");
        for ( int i = 0 ; i < j ; i++ ){
            printf("#");
            for ( int k = 0 ; k < j ; k++ )
                printf("J");
            printf("#\n");
        }
        for ( int i = 0 ; i < N ; i++ ) printf("#");
        printf("\n\n");
    }
    return 0;
}