#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
int main(){
    char pal[2][11];
    scanf("%s%s", pal[0], pal[1]);
    int len = (int)strlen(pal[1]);
    int digit = (int)(len-strlen(pal[0]));
    memcpy(pal[0]+digit, pal[0], sizeof(char)*strlen(pal[0]));
    for( int i = 0 ; i < digit ; ++i ) pal[0] [i]= '0';
//    printf("%s\n%s\n", pal[0], pal[1]);
    int ret = 0;
    for( int i = 0 ; i < len ; ++i ){
        if( pal[0][i] == pal[1][i]  ){
            if(pal[0][i] == '8') ++ret;
        }
        else {
            break;
        }
    }
    printf("%d", ret);
    return 0;
}