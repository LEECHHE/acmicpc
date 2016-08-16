#include <cstdio>
using namespace std;

int main()
{
    int x[3];
    int y[3];
    scanf("%d %d", &x[0], &y[0]);
    scanf("%d %d", &x[1], &y[1]);
    scanf("%d %d", &x[2], &y[2]);
    if ( x[0] == x[1] ) x[0] = x[1] = 0;
    if ( x[0] == x[2] ) x[0] = x[2] = 0;
    if ( x[1] == x[2] ) x[1] = x[2] = 0;
    
    if ( y[0] == y[1] ) y[0] = y[1] = 0;
    if ( y[0] == y[2] ) y[0] = y[2] = 0;
    if ( y[1] == y[2] ) y[1] = y[2] = 0;
   
    for ( int i = 0 ; i < 3 ; ++i ) if( x[i] != 0 ) printf("%d ", x[i]);
    for ( int i = 0 ; i < 3 ; ++i ) if( y[i] != 0 ) printf("%d", y[i]);
    
    return 0;
}