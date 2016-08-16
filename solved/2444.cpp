#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
  
    for( int i = 0 ; i < n - 1 ; i++ ){
        for ( int k = 0 ; k < n - i - 1 ; k ++ )
            printf(" ");
        for ( int j = 0 ; j < 2 * i + 1; j++ )
            printf("*");
        printf("\n");
    }
    for( int i = 0 ; i < n ; i++ ){
        for ( int k = 0 ; k <  i  ; k ++ )
            printf(" ");
        for ( int j = 0 ; j < 2 * (n- i) - 1; j++ )
            printf("*");
        printf("\n");
    }
    return 0;
}