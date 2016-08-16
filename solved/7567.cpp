#include <cstdio>
#include <cstring>
using namespace std;

int main () {
    char bowl[51];
    scanf("%s", bowl);
    int height = 10;
    char current = bowl[0];
    for ( int i = 1 ; i < strlen(bowl) ; i++ ){
        if ( current == bowl[i] )
            height += 5;
        else{
            height += 10;
            current = bowl[i];
        }
    }
    printf("%d", height);
    return 0;
}