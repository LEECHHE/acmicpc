#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> intPair;
char seq[25][25];
int cnt(int visited){
    int ret = 0;
    for( int i = 0 ; i < 26 ; ++i ){
        ret += ((visited & 1<<i) > 0);
    }
    return ret;
}
int main(){
    int r,c; scanf("%d%d",&r,&c);
    for( int i = 0 ; i < r ; ++i ){
        scanf("%s", seq[i]);
    }
    int ret = 0;
    queue<pair<intPair, int>> q;
    int visited = 1<<(seq[0][0]-'A');
    q.push(make_pair(make_pair(0, 0), visited));
    while(!q.empty()){
        pair<intPair, int> cur = q.front();
        intPair pos = cur.first;
        visited = cur.second;
        q.pop();
        int x = pos.first; int y = pos.second;
        
        bool goNext = false;
        if( x > 0 ){
            int next = 1 << (seq[x-1][y]-'A');
            if( (visited & next) == 0){
                q.push(make_pair(make_pair(x-1, y), visited | next));
                goNext = true;
            }
        }
        if( x < r-1 ){
            int next = 1 << (seq[x+1][y]-'A');
            if( (visited & next) == 0){
                q.push(make_pair(make_pair(x+1, y), visited | next));
                goNext = true;
            }
        }
        if( y > 0 ){
            int next = 1 << (seq[x][y-1]-'A');
            if( (visited & next) == 0){
                q.push(make_pair(make_pair(x, y-1), visited | next));
                goNext = true;
            }
        }
        if( y < c-1 ){
            int next = 1 << (seq[x][y+1]-'A');
            if( (visited & next) == 0){
                q.push(make_pair(make_pair(x, y+1), visited | next));
                goNext = true;
            }
        }
        if( !goNext ){
            ret = max( ret, cnt(visited));
        }
    }
    printf("%d", ret);
    return 0;
}