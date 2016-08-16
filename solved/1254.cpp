#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char s[1001]; scanf("%s", s);
    if( strlen(s) == 1 ){
        printf("1");
        return 0;
    }
    char par[2001]; strcpy(par, s);
    int i = 0;
    for( ; i <= strlen(s) ; ++i ){
        par[strlen(s)+i] = '\0';
        for( int j = 0 ; j < i ; ++j )
            par[strlen(s)+i-j-1] = s[j];
        bool success = true;
        for ( int j = 0 ; j <= strlen(par)/2-1 ; ++j ){
            if( par[j] != par[strlen(par)-j-1] ) {
                success = false;
                break;
            }
        }
        if( success ){
            printf("%d", (int)strlen(par));
            return 0;
        }
    }
    return 0;
}