#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int dx[30];
int dy[30];
int main(){
    int N; scanf("%d", &N);
    int x = 0, y = 0;
    for( int i = 0; i < N ; ++i ){
        scanf("%d%d",&dx[i],&dy[i]);
        x += dx[i]; y += dy[i];
    }
    printf("%d %d\n",x,y);
    int removedIndex = -1;
    int min = 1000000000;
    for( int i = 0 ; i < N ; ++i ){
        if ((dx[i]-x)*(dx[i]-x) + (dy[i]-y)*(dy[i]-y) < min ){
            removedIndex = i;
            min = (dx[i]-x)*(dx[i]-x) + (dy[i]-y)*(dy[i]-y);
        }
    }
    if(removedIndex<0) return -1;
    x -= dx[removedIndex]; y -= dy[removedIndex];
    printf("%.2lf", sqrt(x*x+y*y));
    return 0;
}