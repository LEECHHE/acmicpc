#include <cstdio>
using namespace std;
int main(){
    while(1){
        int n; scanf("%d",&n);
        if( n == 0 ) break;
        char words[5001][81];
        for( int i = 0 ; i < n ; ++i ){
            scanf("%s", words[i]);
        }
        int len = n/2 + n%2;
        for( int i = 0 ; i < n ; ++ i){
            printf("%s\n",words[i/2+len*(i%2)]);
        }
    }
    return 0;
}