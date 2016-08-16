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
//const int INF = 987654321;
int box[102][102][102]; //h, n, m
class BoxInfo{
public:
    int level;
    int height;
    int width;
    BoxInfo(){}
    BoxInfo( int level, int height, int width):
        level(level), height(height), width(width) {}
};

queue<BoxInfo> AboutToMature;
int m,n,h;
int immature = 0;
int mature = 0;
int empty = 0;
int days = -1;

void Enqueue(int level, int height, int width){
    if(level == 0 || level > h ) return;
    int* current = &box[level][height][width];
    if(*current != 0 ) return;
    
    --immature;
    ++mature;
    *current = 1;
    
    AboutToMature.push(BoxInfo(level, height, width));
}
bool BFS(){
    while(!AboutToMature.empty()){
        int currentSize = (int)AboutToMature.size();
        for ( int i = 0 ; i < currentSize ; ++i ){
            BoxInfo current = AboutToMature.front();
            Enqueue(current.level-1, current.height, current.width);
            Enqueue(current.level+1, current.height, current.width);
            Enqueue(current.level, current.height-1, current.width);
            Enqueue(current.level, current.height, current.width-1);
            Enqueue(current.level, current.height+1, current.width);
            Enqueue(current.level, current.height, current.width+1);
            
            AboutToMature.pop();
        }
        ++days;
    }
    
    return immature == 0;
}

int main(){

    scanf("%d%d%d", &m, &n, &h);
    for( int i = 0 ; i <= h+1 ; ++i ){
        for( int j = 0 ; j <= n+1 ; ++j ){
            for( int k = 0 ; k <= m+1 ; ++k ){
                box[i][j][k] = -1;
            }
        }
    }
    for( int level = 1 ; level <= h ; ++level ){
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= m ; ++j ){
                scanf("%d", &box[level][i][j]);
                int current = box[level][i][j];
                if( current == 0 ) ++immature;
                else if( current == 1 ){
                    ++mature;
                    AboutToMature.push(BoxInfo(level, i, j));
                }
                else ++empty;
            }
        }
    }
    
    bool AllIsMature = BFS();
    if( days < 0 ) ++days;
    if(!AllIsMature){
        days = -1;
    }
    printf("%d", days);
    return 0;
}