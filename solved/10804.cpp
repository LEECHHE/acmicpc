#include <cstdio>
#include <algorithm>
using namespace std;
int card[21];
int main(){
    for( int i = 1 ; i <= 20 ; ++i ) card[i] = i;
    for( int i = 0 ; i < 10 ; ++i ){
        int b,e; scanf("%d%d",&b,&e);
        reverse(card+b, card+e+1);
    }
    for( int i = 1 ; i <= 20 ; ++i )printf("%d ",card[i]);
    return 0;
}