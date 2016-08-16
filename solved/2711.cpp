#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        char input[81];
        int miss;
        scanf("%d %s", &miss, input);
        int len = (int)strlen(input);
        for( int i = 0 ; i < len ; i++ ){
            if ( i == miss -1 ) continue;
            
            printf("%c", input[i]);
        }
        printf("\n");
    }
    return 0;
}