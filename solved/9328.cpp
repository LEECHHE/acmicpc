#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> intPair;
int h,w;
char grid[105][105];
bool visited[105][105] = { false };
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
bool isDoor(char c){
    return 'A' <= c && c <= 'Z';
}
bool hasKeyToDoor(char c, int key){
    return (1<<(c-'A')) & key;
}
bool isWall(char c){
    return c == '*';
}
bool isKey(char c){
    return 'a' <= c && c <= 'z';
}
bool isDocument(char c){
    return c == '$';
}
bool isValid(int x, int y){
    return 0<=x && x<=h+1 && 0<=y&&y<=w+1;
}void resetMap(){
    memset(visited, 0, sizeof(visited));
}
int steal(int x, int y, int key){
    vector<intPair> founds;
    queue<intPair> q;
    q.push(intPair(x,y));
    visited[x][y] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for( int d = 0 ; d < 4 ; ++d ){
            int cx = x+dx[d], cy = y+dy[d];
            if (!isValid(cx, cy) || visited[cx][cy] || isWall(grid[cx][cy])) continue;
            char c = grid[cx][cy];
            if( isDoor(c) && !hasKeyToDoor(c, key)) continue;
            else if( isKey(c) ){
                int before = key;
                key |= 1<<(c-'a');
                if( before != key ){
                    q = queue<intPair>();
                    resetMap();
                }
            }
            else if( isDocument(c) ){
                bool isNew = true;
                for( auto f : founds ){
                    if( f.first == cx && f.second == cy ){
                        isNew = false;
                        break;
                    }
                }
                if( isNew ){
                    founds.push_back(intPair(cx,cy));
                }
            }
            visited[cx][cy] = true;
            q.push(intPair(cx,cy));
        }
    }
    return (int)founds.size();
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&h,&w);
        memset(grid, 0, sizeof(grid));
        memset(visited, 0, sizeof(visited));
        for( int i = 0 ; i <= w+1 ; ++i ){
            grid[0][i] = grid[h+1][i] = '.';
        }
        for( int i = 1 ; i <= h ; ++i ){
            scanf("%s", grid[i]+1);
            grid[i][0] = grid[i][w+1] = '.';
        }
        //Get the list of keys in bitmask
        int key = 0;
        char has[27]; scanf("%s",has);
        if( has[0] != '0' ){
            for( int i = 0 ; i < strlen(has) ; ++i ){
                key |= 1<<(has[i]-'a');
            }
        }
        printf("%d\n",steal(0,0,key));
    }
    return 0;
}