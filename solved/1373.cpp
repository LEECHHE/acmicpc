#include <cstdio>
#include <cstring>
using namespace std;

char input[10000001];
int main(){
    scanf("%s", input);
    
    int length = (int)strlen( input );
    int current = 0;
    if ( length % 3 == 1 ){
        printf("1");
        current++;
    }
    else if ( length % 3 == 2 ){
        printf("%d", input[1] - '0' + 2);
        current += 2;
    }
    for ( ; current < length ; current += 3 ){
        printf("%d", (input[current] - '0') * 4
               + (input[current+1] - '0') * 2
               + (input[current+2] - '0'));
    }
    
    return 0;
}