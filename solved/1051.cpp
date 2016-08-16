#include<cstdio>
#include<stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main(void)
{
    char world[51][51];
    int n,m;
    scanf("%d%d",&n,&m);
    
    for( int i = 0 ; i < n ; ++i )
        scanf("%s", world[i]);
    int limit = n < m ? n : m;
    int maxSize = 0;
    for ( int size = 1 ; size <= limit ; ++size ){
        int current_x = 0;
        int current_y = 0;
        while( current_x < n - size + 1 ){
            current_y=0;
            while ( current_y < m - size + 1){
                if( world[current_x][current_y] == world[current_x + size - 1][current_y + size - 1] &&
                   world[current_x][current_y] == world[current_x + size - 1][current_y] &&
                   world[current_x][current_y] == world[current_x][current_y + size - 1]){
                    if( maxSize < size*size )
                        maxSize = size * size;
                }
                current_y++;
            }
            current_x++;
        }
    }
    printf("%d", maxSize);
    return 0;
}