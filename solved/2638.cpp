#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> intPair;
int chz[101][101];
int n,m;
void bfs( int x, int y , int marked, int target){
    queue<intPair> q;
    q.push(make_pair(x,y));
    chz[x][y] = marked;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if( x > 1 ){
            if( chz[x-1][y] == target ){
                chz[x-1][y] = marked;
                q.push(make_pair(x-1, y));
            }
        }
        if( x < n ){
            if( chz[x+1][y] == target ){
                chz[x+1][y] = marked;
                q.push(make_pair(x+1, y));
            }
        }
        if( y > 1 ){
            if( chz[x][y-1] == target ){
                chz[x][y-1] = marked;
                q.push(make_pair(x, y-1));
            }
        }
        if( y < m ){
            if( chz[x][y+1] == target ){
                chz[x][y+1] = marked;
                q.push(make_pair(x, y+1));
            }
        }
    }
}
bool outside(int x, int y, int marked){
    int cnt = (chz[x-1][y] < 0 && chz[x-1][y] != marked)
            + (chz[x+1][y] < 0 && chz[x+1][y] != marked)
    +(chz[x][y-1]<0 && chz[x][y-1] != marked )
    +(chz[x][y+1] < 0 && chz[x][y+1] != marked);
    return cnt > 1;
}
int melt(int marked){
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= m ; ++j ){
            if( chz[i][j] == 1 ){
                if(outside(i, j, marked)){
                    ++ret;
//                    printf("%d %d is melted\n", i,j);
                    bfs(i, j, marked, 0);
                }
            }
        }
    }
    return ret;
}
void printMap(){
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1; j <= m ; ++j ){
            printf("%d ", chz[i][j]);
        }
        printf("\n");
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int total = 0;
    for( int i = 1; i <= n ; ++i ){
        for( int j = 1 ; j <= m ; ++j ){
            scanf("%d",&chz[i][j]);
            if(chz[i][j] == 1){
                ++total;
            }
        }
    }
    for( int i = 1; i <= n ; ++i ){
        chz[i][m+1] = chz[i][0] = -100;
        if( chz[i][1] == 0 ){
            bfs(i, 1, -100, 0);
        }
        if( chz[i][m] == 0 ){
            bfs(i,m,-100,0);
        }
    }
    for( int i = 1 ; i <= m ; ++i ){
        chz[0][i] = chz[n+1][i] = -100;
        if( chz[1][i] == 0 ){
            bfs(1,i,-100,0);
        }
        if( chz[n][i] == 0 ){
            bfs(n,i,-100,0);
        }
    }
//    printMap();
    int turn = 0;
    int cnt = 0;
    while(total){
        ++turn;
        int melted = melt(-turn);
        total -= melted;
        cnt = melted;
//        printMap();
//        printf("%d is melted\n", melted);
    }
    printf("%d",turn);
    
    return 0;
}