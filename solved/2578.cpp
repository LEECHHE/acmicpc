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
#include <cstring>
using namespace std;

int bingo[5][5];
vector<pair<pair<int, int>, int>> lines;    // <x,y>, direction
pair<int, int> find(int value){
    pair<int, int> res = make_pair(-1, -1);
    for( int i = 0 ; i < 5 ; ++i ){
        for( int j = 0 ; j < 5 ; ++j ){
            if( value == bingo[i][j] ){
                res.first = i;
                res.second = j;
                break;
            }
        }
    }
    return res;
}

bool AlreadyIncluded(int pos, int direction){
    bool isIncluded = false;
    for( auto line : lines){
        if( line.second == direction ){
            if( direction >= 2){
                //diagonal
                isIncluded = true;
                break;
            }
            if(( direction == 0 && pos == line.first.first) ||
               ( direction == 1 && pos == line.first.second) ){
                isIncluded = true;
                break;
            }
        }
    }
    return isIncluded;
}

bool checkOnDirection( int pos, int direction){
    if(direction == 0 ){
        for( int i = 0 ; i < 5 ; ++i ){
            if( bingo[pos][i] > 0 ) return false;
        }
    }
    else if( direction == 1){
        for( int i = 0 ; i < 5 ; ++i ){
            if( bingo[i][pos] > 0 ) return false;
        }
    }
    else if( direction == 2 ){
        for( int i = 0 ; i < 5 ; ++i ){
            if(bingo[4-i][i] > 0) return false;
        }
    }
    else if( direction == 3){
        for( int i = 0 ; i < 5 ; ++i ){
            if(bingo[i][i] > 0) return false;
        }
    }
    
    return AlreadyIncluded(pos, direction) ? false : true;
}
void AddLine(pair<int, int> grid, int direction){
    lines.push_back(make_pair(grid, direction));
}
void checkBingo(pair<int, int> grid){
    if(checkOnDirection(grid.first, 0)){
        AddLine(grid, 0);
    }
    if(checkOnDirection(grid.second, 1)){
        AddLine(grid, 1);
    }
    if( grid.first + grid.second == 4){
        if(checkOnDirection(grid.first, 2)) AddLine(grid, 2);
    }
    if( grid.first == grid.second){
        if(checkOnDirection(grid.first, 3)) AddLine(grid, 3);
    }
}
int main(){
    for( int i = 0 ; i < 5 ; ++i ){
        for( int j = 0 ; j < 5 ; ++j ){
            scanf("%d", &bingo[i][j]);
        }
    }

    int ans = 4;
    for( int i = 0 ; i < 4 ; ++i ){
        int temp; scanf("%d", &temp);
        pair<int, int> grid = find(temp);
        bingo[grid.first][grid.second] = -1;
    }
    while( lines.size() < 3 ){
        int temp; scanf("%d", &temp);
        pair<int, int> grid = find(temp);
        bingo[grid.first][grid.second] = -1;
        checkBingo(grid);

        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}