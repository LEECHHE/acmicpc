#include <cstdio>
#include <cstring>
using namespace std;
char cell[6565][6565];
void setStar(int x, int y, int size){
    if( size == 1 ){
        cell[x][y] = '*';
        return;
    }
    int sze = size/3;
    setStar(x, y, sze);
    setStar(x, y+sze, sze);
    setStar(x, y+sze*2, sze);
    setStar(x+sze, y, sze);
//    setStar(x+sze, y+sze, sze);
    setStar(x+sze, y+sze*2, sze);
    setStar(x+sze*2, y, sze);
    setStar(x+sze*2, y+sze, sze);
    setStar(x+sze*2, y+sze*2, sze);
}
int main(){
    int size; scanf("%d",&size);
    char init[6565]; for( int i = 0 ; i <= size ; ++i ) init[i] = ' ';
    init[size+1] = '\0';
    for( int i = 0 ; i <= size ; ++i ){
        memcpy(cell[i], init, sizeof(init));
    }
    setStar(1, 1, size);
    for( int i = 1 ; i <= size ; ++i ){
        printf("%s\n", cell[i]+1);
    }
    return 0;
}