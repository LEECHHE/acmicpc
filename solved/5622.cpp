#include <cstdio>
using namespace std;
int find(char u){
    if( u <= 'C' ) return 3;
    else if( 'D' <= u && u <= 'F' ) return 4;
    else if( 'G' <= u && u <= 'I' ) return 5;
    else if( 'J' <= u && u <= 'L' ) return 6;
    else if( 'M' <= u && u <= 'O' ) return 7;
    else if( 'P' <= u && u <= 'S' ) return 8;
    else if( 'T' <= u && u <= 'V' ) return 9;
    else if( 'W' <= u ) return 10;
    return 11;
}
int main(){
    char dial[16]; scanf("%s",dial);
    int ret = 0;
    for( int i = 0 ; ;++i ){
        if( dial[i] =='\0') break;
        ret += find(dial[i]);
    }
    printf("%d", ret);
    return 0;
}