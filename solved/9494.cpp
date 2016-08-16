#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    while(1){
        int N;
        int current = 1;
        scanf("%d", &N);
        if ( !N ) break;
        
        getchar();
        while ( N-- > 0 ){
            char input[1001];
            gets(input);
            
            if ( strlen(input) < current )
                continue;

            for ( int i = current ; i <= strlen(input) ; i++ ){
                if ( input[i] == ' ' || input[i] == '\n' || input[i] == 0 ){
                    current = i;
                    break;
                }
            }       }
        printf("%d\n", current+1);
    }
    return 0;
}