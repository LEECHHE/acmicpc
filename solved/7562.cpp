#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> intPair;
const int INF = (1<<31)-1;
int cell[300][300] = { 0 };
int l;
void push(queue<intPair>& q, int x, int y, int dist){
    if( x < 0 || x >= l ) return;
    if( y < 0 || y >= l ) return;
    if( cell[x][y] <= dist+1 ) return;
    cell[x][y] = dist+1;
    q.push(make_pair(x, y));
}
int main(){
    int c; scanf("%d",&c);
    while(c--){
        scanf("%d",&l);
        for( int i = 0 ; i < l ; ++i ){
            for( int j = 0 ; j < l ; ++j ){
                cell[i][j] = INF;
            }
        }
        queue<intPair> q;
        intPair start, des;
        scanf("%d%d%d%d", &start.first, &start.second, &des.first,&des.second);
        q.push(start);
        cell[start.first][start.second] = 0;
        int ret = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int dist = cell[x][y];
            q.pop();
            
            if( x == des.first && y == des.second ){
                ret = cell[x][y];
                break;
            }
            push(q, x-1, y-2, dist);
            push(q, x-1, y+2, dist);
            push(q, x-2, y-1, dist);
            push(q, x-2, y+1, dist);
            push(q, x+1, y-2, dist);
            push(q, x+1, y+2, dist);
            push(q, x+2, y-1, dist);
            push(q, x+2, y+1, dist);
        }
        printf("%d\n", ret);
    }
    return 0;
}