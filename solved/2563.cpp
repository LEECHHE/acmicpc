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
bool covered[101][101] = { false };
bool cover[10];
int main(){
    int n;
    for( int i = 0 ; i < 10 ; ++i ) cover[i] = true;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        for( int j = a ; j <= a+9 ; ++j )
            memcpy(&covered[j][b], cover, sizeof(cover));
    }
    int ret= 0;
    for( int i = 1 ; i <= 100 ; ++i ){
        for( int j = 1 ; j <= 100 ; ++j ){
            if(covered[i][j]) ret++;
        }
    }
    printf("%d",ret);
    return 0;
}