#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> intPair;
int n,m;
int glac[305][305] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };
int value(int x, int y){
    if(( x < 0 || x >= n ) || (y < 0 || y >= m )) return -1;
    return glac[x][y];
}
bool melt(){
    bool isMelted = false;
    for (int i = 0 ; i < n ; ++i) {
        for( int j = 0 ; j < m ; ++j ){
            if( glac[i][j] > 0 ){
                isMelted = true;
                for( int k = 0 ; k < 4 ; ++k ){
                    glac[i][j] -= value(i+dx[k], j+dy[k]) == 0;
                }
                if( glac[i][j] <= 0 ) glac[i][j] = -1;
            }
        }
    }
    if (!isMelted) return false;
    for (int i = 0 ; i < n ; ++i ) {
        for( int j = 0 ; j < m ; ++j ){
            if (glac[i][j] < 0) {
                glac[i][j] = 0;
            }
        }
    }
    return true;
}
bool hasSplited(){
    bool hasFound = false;
    bool visited[305][305] = { false };
    queue<intPair> q;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            if( glac[i][j] > 0 && !visited[i][j] ){
//                printf("found on %d,%d\n", i,j);
                if(hasFound)
                    return true;
                hasFound = true;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for (int k = 0; k < 4 ; ++k) {
                        int _x = x+dx[k], _y = y+dy[k];
                        if(value(_x,_y) > 0 && !visited[_x][_y] ){
                            visited[_x][_y] = true;
                            q.push(make_pair(_x, _y));
                        }
                    }
                }
            }
        }
    }
    return false;
}
//void print(){
//    for( int i = 0 ; i < n ; ++i ){
//        for( int j = 0 ; j < m ; ++j ){
//            printf("%d ", glac[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
int main(){
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j )
            scanf("%d",&glac[i][j]);
    }
    int ret;
    for (ret = 0; ; ++ret) {
        if( hasSplited() )
            break;
//        print();
        if(!melt()){
            ret = 0;
            break;
        }

    }
    printf("%d", ret);
    return 0;
}