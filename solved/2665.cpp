#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
const int INF = 50000;
typedef pair<int, int> intPair;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
int main(){
    int n; scanf("%d",&n);
    char cell[51][50];
    int cost[50][50];
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", cell[i]);
        for( int j = 0 ; j < n ; ++j ){
            cost[i][j] = INF;
        }
    }
    cost[0][0] = cell[0][0] == '0';
    queue<intPair> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for( int i = 0 ; i < 4 ; ++i ){
            int _x = dx[i]+x;
            int _y = dy[i]+y;
            if(!( 0<= _x && _x < n) ) continue;
            if(!( 0<= _y && _y < n )) continue;
            int next_cost = cost[x][y] + (cell[_x][_y] == '0');
            if( cost[_x][_y] > next_cost){
                cost[_x][_y] = next_cost;
                q.push(make_pair(_x, _y));
            }
        }
    }
    printf("%d", cost[n-1][n-1]);
    return 0;
}