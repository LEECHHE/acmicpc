#include <cstdio>
using namespace std;

int start_x, start_y, end_x, end_y;

bool start_inCircle( int x, int y, int r ){
    return (r * r) > (x-start_x) * (x-start_x) + (y - start_y) * (y - start_y);
}
bool end_inCircle( int x, int y, int r){
    return (r * r) > (x-end_x) * (x-end_x) + (y - end_y) * (y - end_y);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y );
        int planet_num;
        scanf("%d", &planet_num);
        int count = 0;
        while( planet_num-- ){
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r );
            if ( start_inCircle( x, y, r )^end_inCircle( x, y, r ) ){
                count++;
            }
        }
        printf("%d\n", count);
        
    }
    return 0;
}