#include <cstdio>
using namespace std;

int main(){
    while(1){
        int input[2];
        scanf( "%d %d", &input[0], &input[1] );
        
        if( !input[0] && !input[1] ){
            break;
        }
        else if( !(input[1] % input[0]) ){
            printf("factor\n");
        }
        else if( !(input[0] % input[1]) ){
            printf("multiple\n");
        }
        else
            printf("neither\n");
    }
    return 0;
    
}