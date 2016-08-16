#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int N;
    char pivot[51];
    char input[51];
    
    scanf("%d", &N);
    scanf("%s", pivot);
    
    int len = (int)strlen(pivot);
    while(--N){
        scanf("%s", input);
        for( int i = 0; i < len ; i++ ){
            if( pivot[i] != input[i] ){
                pivot[i] = '?';
            }
        }
    }
    
    printf("%s", pivot);
    return 0;
}