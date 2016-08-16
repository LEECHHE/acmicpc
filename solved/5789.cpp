#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int N;
    scanf( "%d", &N );
    
    while(N--){
        char input[1001];
        scanf( "%s", input );
    
        if ( input[strlen(input)/2-1] == input[strlen(input)/2])
            printf("Do-it\n");
        else
            printf("Do-it-Not\n");
    }
    return 0;
}