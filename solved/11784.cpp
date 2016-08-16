#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int toint(char c){
    if( c <= '9' ) return c-'0';
    return c-'A'+10;
}
int main(){
    char seq[251];
    while (scanf("%s", seq) != -1) {
        for( int i = 0 ; i < strlen(seq) ; ){
            printf("%c",toint(seq[i])*16+toint(seq[i+1]));
            i += 2;
        }
        printf("\n");
    }
    return 0;
}