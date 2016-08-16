#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
    int count = 0;
    char input[3];
    char check[3];
    
    scanf("%s", input);
    
    if(strlen(input) == 1) {
        input[1] = input[0];
        input[0] = '0';
    }
    memcpy( check, input, strlen(input) );

    while(1){
        check[count++ % 2] = (char)((((check[0] - '0') + (check[1] - '0')) % 10) + '0');

        if(( count - 1 ) % 2) {          //홀수번 째 [0][1]
            if( check[0] == input[0] && check[1] == input[1] ){
                printf("%d", count);
                return 0;
            }
        }
        else{
            if ( check[0] == input[1] && check[1] == input[0] ){
                printf("%d", count);
                return 0;
            }
        }
    }
    return 0;
    
}