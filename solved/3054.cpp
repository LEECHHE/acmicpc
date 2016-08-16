#include <cstdio>
#include <cstring>
using namespace std;
//1022

char l[5][100];
int main(){
    char seq[16]; scanf("%s", seq);
    int len = 4*(int)strlen(seq)+1;
    for ( int i = 0 ; i < 5 ; ++i) {
        for( int j = 0 ; j <= len ; ++j ){
            l[i][j] = '.';
        }
        l[i][len] = '\0';
    }
    char cover;
    for( int i = 0 ; i < strlen(seq) ; ++i ){
        cover = i%3 ==2 ? '*': '#';
        int start = 4*i;
        for (int dist = 0; dist <= 2; ++dist) {
            l[2+dist][start+dist] = l[2-dist][start+dist] = cover;
        }
        l[1][start+3] = l[3][start+3] =cover;
        l[2][start+2] = seq[i];
        if( i > 0 && i % 3 == 0 ) l[2][start] ='*';
    }
    l[2][len-1] = cover;
    for( int i = 0 ; i < 5 ; ++i ){
        printf("%s\n", l[i]);
    }
    return 0;
}