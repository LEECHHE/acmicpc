#include <cstring>
#include <cstdio>
using namespace std;

bool cups[3] = { false };
void swap(int a, int b){
    bool t = cups[a];
    cups[a] = cups[b];
    cups[b] = t;
}
void shuffle(char s){
    switch (s) {
        case 'A':
            swap(0,1);
            break;
        case 'B':
            swap(1,2);
            break;
        case 'C':
            swap(0,2);
            break;
    }
}
int main(){
    char orders[51];
    scanf("%s", orders);
    cups[0] = true;
    for ( int i = 0 ; i < strlen(orders) ; ++i ){
        shuffle(orders[i]);
    }
    for( int i = 0 ; i < 3 ; ++i ){
        if( cups[i] ) printf("%d", i+1);
    }
    return 0;
}