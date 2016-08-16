#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> intPair;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    char cell[105][105];
    for( int i = 1 ; i <= n ; ++i ){
        scanf("%s", cell[i]+1);
    }
    queue<pair<intPair, int>> q;
    q.push(make_pair(make_pair(1, 1),1));
    while(!q.empty()){
        pair<intPair, int> cur = q.front();
        int x = cur.first.first;
        int y = cur.first.second;
        int step = cur.second;
        q.pop();
        
        if( x == n && y == m ){
            printf("%d", step);
            break;
        }
        if( cell[x-1][y] == '1' ){
            cell[x-1][y] = '0';
            q.push(make_pair(make_pair(x-1, y), step+1));
        }
        if( cell[x+1][y] == '1' ){
            cell[x+1][y] = '0';
            q.push(make_pair(make_pair(x+1, y), step+1));
        }
        if( cell[x][y-1] == '1' ){
            cell[x][y-1] = '0';
            q.push(make_pair(make_pair(x, y-1), step+1));
        }
        if( cell[x][y+1] == '1' ){
            cell[x][y+1] = '0';
            q.push(make_pair(make_pair(x, y+1), step+1));
        }
    }

    return 0;
}