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
int n, m;
string board[51];
string cand[9] = {
"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"
};
int cmp( int x, int y ){
    int white = 0;
    int black = 0;
    for( int i = x ; i < x+8 ; ++i ){
        for( int j = y ; j < y+8 ; ++j ){
            if( cand[i-x][j-y] != board[i][j] ){
//                printf("white: %d,%d\n", i,j);
                ++white;
            }
            if( cand[i+1-x][j-y] != board[i][j] ){
//                printf("black: %d,%d\n", i,j);
                ++black;
            }
        }
//        printf("\n");
    }
//    printf("(%d,%d)\n", white, black);
    return min(white,black);
}
int main(){
    scanf("%d%d", &n, &m);
    for( int i = 0 ; i < n ; ++i ){
        char temp[51];
        scanf("%s", temp);
        board[i] = string(temp);
    }
    int ret = (1<<31)-1;
    for( int i = 0 ; i < n-7 ; ++i ){
        for( int j = 0 ; j < m-7 ; ++j ){
            ret = min(ret, cmp(i,j));
        }
    }
    printf("%d", ret);
    return 0;
}