#include <cstdio>
using namespace std;
bool grid[2050][2050] = { false };
int main(){
    int t; scanf("%d",&t);
    char op[1001]; scanf("%s", op);
    int x = 1000, y = 1000;
    int ret = 1;
    grid[x][y] = 1;
    for( int i = 0 ; i < t ; ++i ){
        if( op[i] == 'E'){
            ++y;
        }
        else if(op[i] == 'W'){
            --y;
        }
        else if(op[i] =='S'){
            ++x;
        }
        else{
            --x;
        }
        ret += !grid[x][y];
        grid[x][y] = 1;
    }
    printf("%d",ret);
    return 0;
}