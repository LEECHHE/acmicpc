#include <cstdio>
#include <cstring>
using namespace std;

int power16(int a, int n){
    if( n == 0 ) return 1;
    else return 16 * power16( a, n-1 );
}
int main(){
    char input[7];
    int result = 0;
    scanf("%s", input);
    for( int digit = 0 ; digit < strlen(input) ; digit++ ){
        if( input[digit] >= '0' && input[digit] <= '9' ){
            result += ( (input[digit] - '0') * power16(16, strlen(input) - digit - 1));
        }
        else{
            result += ( (input[digit] - 'A' + 10) * power16(16, strlen(input) - digit - 1));
        }
    }
    printf("%d", result);
    
    return 0;
}