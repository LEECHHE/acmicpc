#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char seq[101]; scanf("%s", seq);
    int pos[26]; for( int i = 0 ; i < 26 ; ++i ) pos[i] = -1;
    int len = (int)strlen(seq);
    for( int i = 0 ; i < len ; ++i ){
        if( pos[seq[i]-'a'] < 0 ){
            pos[seq[i]-'a'] = i;
        }
    }
    for( int i = 0 ; i < 26 ; ++i ){
        printf("%d ", pos[i]);
    }
    return 0;
}