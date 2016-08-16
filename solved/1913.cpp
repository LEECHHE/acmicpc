#include <cstdio>
using namespace std;

int snail[999][999];

int main(){
    int N, find;
    scanf("%d", &N);
    scanf("%d", &find);
    int number = 1;
    int x = N / 2; int y = N / 2;
    int find_x, find_y;
    
    
    snail[x--][y] = number++;
    for ( int i = 1 ; i < N ; i += 2 ){
        for( int r = 0 ; r <= i ; r++ ){
            if( number == find ){
                find_x = x;
                find_y = y;
            }
            snail[x][y++] = number++;
        }
        y--;
        x++;
        for( int d = 0 ; d <= i ; d++ ){
            if( number == find ){
                find_x = x;
                find_y = y;
            }
            snail[x++][y] = number++;
        }
        x--;
        y--;
        for ( int l = 0 ; l <= i ; l++ ){
            if( number == find ){
                find_x = x;
                find_y = y;
            }
            snail[x][y--] = number++;
        }
        y++;
        x--;
        for ( int u = 0 ; u <= i ; u++ ){
            if( number == find ){
                find_x = x;
                find_y = y;
            }
            snail[x--][y] = number++;
        }
    }
        for ( int i = 0 ; i < N ; i++ ){
            for( int j = 0 ; j < N ; j++ ){
                  printf("%d ", snail[i][j]);
                }
                printf("\n");
            }
    printf("%d %d", find_x+1, find_y+1 );
    
    
    return 0;
}