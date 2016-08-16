#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;

int main(){
    bool connected[9][9] = { false };
    connected[1][4] = connected[1][5]
    = connected[3][4] = connected[3][5]
    = connected[4][3] = connected[4][2] = connected[5][8]
    = connected[6][2] = connected[6][3] = connected[7][8]
    = connected[8][6] = connected[8][7] = true;
    
    for(int i = 1; ;++i){
        char piece[10005]; scanf("%s", piece);
        if( piece[0] == '0' ) break;
        
        char current = piece[0];
        bool success = current == '1' ? true : false;
        for( int idx = 1 ; idx < (int)strlen(piece) ; ++idx ){
            if(!success) break;
            if(connected[current-'0'][piece[idx]-'0']){
                current = piece[idx];
            }
            else{
                success = false;
            }
        }
        if( current != '2' ) success = false;
        printf("%d. ", i);
        if(success) printf("VALID\n");
        else printf("NOT\n");
    }
    return 0;
}