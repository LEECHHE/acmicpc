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
char cell[105][105] = { "#####################################################################################################" };
int main(){
    for( int i = 1 ; i < 105 ; ++i ){
        memcpy(cell[i], cell[0], sizeof(cell[0]));
    }
    int n; char op[51]; scanf("%d%s", &n, op);
    int leftmost = 53;
    int rightmost = 53;
    int upmost = 53;
    int downmost = 53;
    int direction = 0;
    cell[53][53] = '.';
    int x = 53, y = 53;
    for( int i = 0 ; i < n ; ++i ){
        switch (op[i]) {
            case 'L':
                direction = (direction+1)%4;
                break;
            case 'R':
                direction--;
                if( direction < 0 ) direction += 4;
                break;
            case 'F':
                if( direction == 0 ){
                    ++x;
                    downmost = max(downmost, x);
                }
                else if(direction == 1){
                    ++y;
                    rightmost = max(rightmost, y);
                }
                else if( direction == 2 ){
                    --x;
                    upmost = min(upmost, x);
                }
                else if( direction == 3 ){
                    --y;
                    leftmost = min(leftmost, y);

                }
                cell[x][y] = '.';
                break;
        }
    }
    
    for( int i = upmost ; i <= downmost ; ++i ){
        cell[i][rightmost+1] = '\0';
        printf("%s\n", &cell[i][leftmost]);
    }
    return 0;
}