#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char input[10001];
    scanf("%s", input);
    int jol = 0, lol = 0;
    for ( int i = 0 ; i < strlen(input) ; ++i ){
        if( !strncmp( &input[i] , "JOI", 3 ) ){
            i++;
            jol++;
        }
        else if ( !strncmp( &input[i], "IOI" , 3 ) ){
            i++;
            lol++;
        }
    }
    printf("%d\n%d", jol, lol);
    return 0;
}