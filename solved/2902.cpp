#include <cstdio>
#include <cstring>
using namespace std;

char input[101];
int main(){
    scanf("%s", input);
    printf("%c", input[0]);
    for ( int i = 1; i < strlen(input) ; i++ ){
        if( input[i] == '-' )
            printf("%c", input[i+1]);
    }
    return 0;
}