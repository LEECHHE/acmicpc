#include <cstdio>
using namespace std;

char world[50][50];
bool visited[50][50];
int count = 0;
int w, h;

bool findIsland( int x, int y );
int main () {
    while(1){
        scanf("%d %d", &w, &h);
        if ( w == 0 || h == 0 ){
            break;
        }
        count = 0;
        for ( int i = 0 ; i < h ; i++ ){
            for ( int j = 0 ; j < w ; j++ ){
                getchar();
                scanf("%c", &world[i][j]);
                visited[i][j] = false;
            }
        }
        
        for ( int i = 0 ; i < h ; i++ ){
            for( int j = 0 ; j < w ; j++ ){
                if ( findIsland( i, j ) ){
                    count++;
                }
            }
        }
        printf("%d\n", count );
    }
    return 0;
}
bool findIsland( int x , int y ){
    if ( x >= h ) return false;
    if ( y >= w ) return false;
    if ( x < 0 ) return false;
    if ( y < 0 ) return false;
    
    if ( world[x][y] == '0' )
        return false;
    else if( visited[x][y] )
        return false;
    else{
        visited[x][y] = true;
        findIsland( x-1, y);
        findIsland( x-1, y+1 );
        findIsland( x, y+1 );
        findIsland( x+1, y+1 );
        findIsland( x+1, y );
        findIsland( x+1, y-1 );
        findIsland( x, y-1 );
        findIsland( x-1, y-1);
        return true;
    }
}