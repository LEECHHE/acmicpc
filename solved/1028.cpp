#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int r,c; scanf("%d%d",&r,&c);
    char mine[760][760];
    for( int i = 0 ; i < r ; ++i ) scanf("%s", mine[i]);
    
    int maximum = max(r,c);
    maximum = maximum % 2 ? maximum/2+1 : maximum/2;
    int ret = 0;
    for( int size = maximum ; size > 0 ; --size ){
        if(ret) break;
        for( int line = 0 ; line <= r - size*2+1 ; ++line ){
            if(ret) break;
            for( int top = size-1 ; top <= c - size ; ++top ){
                if(ret) break;
                if( mine[line][top] == '1' ){
                    bool isFound = true;
                    int width = 1;
                    for( int i = line+1 ; i < line + size*2-1 ; ++i ){
                        if( mine[i][top-width] != '1' || mine[i][top+width] != '1' ){
                            isFound = false;
                            break;
                        }
                        if( i < line + size -1 ) width++;
                        else width--;
                    }
                    if(isFound){
                        ret = size;
                        break;
                    }
                }
            }
        }
    }
    printf("%d",ret);
    
    return 0;
}