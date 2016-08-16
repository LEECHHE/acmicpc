#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        char test[80];
        scanf("%s", test);
        int score = 0;
        int dup = 1;
        for ( int i = 0 ; i < strlen(test) ; i++ ){
            if( test[i] == 'O' ){
                score += dup++;
            }
            else
                dup = 1;
        }
        printf("%d\n", score);
    }
    return 0;
}