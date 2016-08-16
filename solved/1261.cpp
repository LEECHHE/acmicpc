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
typedef pair<int,int> intPair;
const int INF = (1<<31)-1;
char cell[105][105];
int dist[105][105];
int main(){
    int m,n; scanf("%d%d",&m,&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s",cell[i]);
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0;
    queue<pair<intPair, int>> q;
    q.push(make_pair(make_pair(0, 0),0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        
        if( cost > dist[x][y] ) continue;
        if( x > 0 && dist[x][y]+(cell[x-1][y]=='1') < dist[x-1][y]){
            dist[x-1][y] = dist[x][y]+(cell[x-1][y]=='1');
            q.push(make_pair(make_pair(x-1, y),dist[x-1][y]));
        }
        if( x < n-1 && dist[x][y]+(cell[x+1][y]=='1') < dist[x+1][y]){
            dist[x+1][y] = dist[x][y]+(cell[x+1][y]=='1');
            q.push(make_pair(make_pair(x+1, y),dist[x+1][y]));
        }
        if( y > 0 && dist[x][y]+(cell[x][y-1]=='1') < dist[x][y-1]){
            dist[x][y-1] = dist[x][y]+(cell[x][y-1]=='1');
            q.push(make_pair(make_pair(x, y-1),dist[x][y-1]));
        }
        if( y < m-1 && dist[x][y]+(cell[x][y+1]=='1') < dist[x][y+1]){
            dist[x][y+1] = dist[x][y]+(cell[x][y+1]=='1');
            q.push(make_pair(make_pair(x, y+1),dist[x][y+1]));
        }
    }
    printf("%d\n", dist[n-1][m-1]);
    return 0;
}