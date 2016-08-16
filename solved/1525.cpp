#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map< int, bool > visited;
int p10[] { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int target;
int swap(int orgin, int idx1, int idx2){
    //orgin[idx1] == 0
    char digit[9];
    for( int i = 0 ; i < 9 ; ++i ){
        digit[i] = '0' + orgin/p10[8-i];
        orgin %= p10[8-i];
    }
    digit[idx1] = digit[idx2];
    digit[idx2] = '0';
    int ret = 0;
    for( int i = 0 ; i < 9 ; ++i ){
        ret += p10[8-i] * (digit[i]-'0');
    }
    return ret;
}
int toIndex( int x, int y ){
    return 3*(2-x)+(2-y);
}
int toInt(vector<vector<int>> seq){
    int ret = 0;
    for( int i = 2 ; i >= 0 ; --i ){
        for( int j = 2 ; j >= 0 ; --j ){
            ret += p10[3*(2-i)+(2-j)] * seq[i][j];
        }
    }
    return ret;
}
int bfs(){
    vector<vector<int>> seq(3, vector<int>(3));
    for( int i = 0 ; i < 3 ; ++i ){
        for( int j = 0 ; j < 3 ; ++j ){
            seq[i][j] = 3*i + j+1;
        }
    }
    seq[2][2] = 0;
    
    int start = toInt(seq);
    visited[start] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while(!q.empty()){
        int cur = q.front().first;
        int step = q.front().second;
        if( cur == target ) return step;
        q.pop();

        int x = -1, y = -1;
        int zero_idx = -1;
        for( int i = 0 ; i < 3 ; ++i ){
            for( int j = 0 ; j < 3 ; ++j ){
                if(cur%p10[3*i+j+1]/p10[3*i+j] == 0){
                    x = i;
                    y = j;
                    zero_idx = toIndex(x,y);
                    break;
                }

            }
            if( zero_idx >= 0 ) break;
        }
        
        if( x > 0 ){
            int moved = swap(cur, zero_idx, toIndex(x-1, y));

            bool& isVisited = visited[moved];
            if( !isVisited ){
                isVisited = true;
                q.push(make_pair(moved,step+1));
            }
        }
        if( x < 2 ){
            int moved = swap(cur, zero_idx, toIndex(x+1, y));

            bool& isVisited = visited[moved];
            if( !isVisited ){
                isVisited = true;
                q.push(make_pair(moved,step+1));
            }
        }
        if( y > 0 ){
            int moved = swap(cur, zero_idx, toIndex(x, y-1));

            bool& isVisited = visited[moved];
            if( !isVisited ){
                isVisited = true;
                q.push(make_pair(moved,step+1));
            }
        }
        if( y < 2 ){
            int moved = swap(cur, zero_idx, toIndex(x, y+1));

            bool& isVisited = visited[moved];
            if( !isVisited ){
                isVisited = true;
                q.push(make_pair(moved,step+1));
            }
        }
    }
    return -1;
}
int main(){
    for( int i = 0 ; i < 9 ; ++i ){
        int t; scanf("%d",&t);
        target += p10[8-i]*t;
    }
    printf("%d", bfs());
    return 0;
}