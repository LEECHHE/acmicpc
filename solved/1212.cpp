#include <cstdio>
#include <cstring>
using namespace std;

char input[333334];
int main(){
    scanf("%s", input);
    int length = (int)strlen( input );
    
    switch ( input[0] ){
        case '1':
            printf("1");
            break;
        case '2':
            printf("10");
            break;
        case '3':
            printf("11");
            break;
        case '4':
            printf("100");
            break;
        case '5':
            printf("101");
            break;
        case '6':
            printf("110");
            break;
        case '7':
            printf("111");
            break;
    }
    for ( int i = 1 ; i < length ; i++ ){
        switch ( input[i] ){
            case '0' :
                printf("000");
                break;
            case '1':
                printf("001");
                break;
            case '2':
                printf("010");
                break;
            case '3':
                printf("011");
                break;
            case '4':
                printf("100");
                break;
            case '5':
                printf("101");
                break;
            case '6':
                printf("110");
                break;
            case '7':
                printf("111");
                break;
        }
    }
    return 0;
}