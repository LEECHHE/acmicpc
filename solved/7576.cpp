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
int box[1000][1000]; //n, m
class BoxInfo{
public:
    int height;
    int width;
    BoxInfo(){}
    BoxInfo( int height, int width):
    height(height), width(width) {}
};

queue<BoxInfo> AboutToMature;
int m,n;
int immature = 0;
int mature = 0;
int empty = 0;
int days = -1;

void Enqueue(int height, int width){
    if( height < 0 || height >= n ) return;
    if( width < 0 || width >= m ) return;
    int* current = &box[height][width];
    if(*current != 0 ) return;
    
    --immature;
    ++mature;
    *current = 1;
    
    AboutToMature.push(BoxInfo(height, width));
}
bool BFS(){
    while(!AboutToMature.empty()){
        int currentSize = (int)AboutToMature.size();
        for ( int i = 0 ; i < currentSize ; ++i ){
            BoxInfo current = AboutToMature.front();
            Enqueue(current.height-1, current.width);
            Enqueue(current.height, current.width-1);
            Enqueue(current.height+1, current.width);
            Enqueue(current.height, current.width+1);
            
            AboutToMature.pop();
        }
        ++days;
    }
    
    return immature == 0;
}

int main(){
    
    scanf("%d%d", &m, &n);

    for( int j = 0 ; j < n ; ++j ){
        for( int k = 0 ; k < m ; ++k ){
            box[j][k] = -1;
        }
    }


    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            scanf("%d", &box[i][j]);
            int current = box[i][j];
            if( current == 0 ) ++immature;
            else if( current == 1 ){
                ++mature;
                AboutToMature.push(BoxInfo(i, j));
            }
            else ++empty;
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