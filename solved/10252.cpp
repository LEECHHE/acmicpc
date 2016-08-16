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
#include <cstring>
using namespace std;
//const int INF = 987654321;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int m,n; scanf("%d%d", &m, &n);
        printf("1\n");
        for( int i = 0 ; i < n ; ++i){
            printf("(%d,%d)\n", 0, i);
        }
        
        for( int i = n-1 ; i >= 0 ; --i ){
            for( int j = m - 1 ; j >= 1 ; --j ){
                printf("(%d,%d)\n", j, i);
            }
            --i;
            if( i < 0 ) break;
            for( int j = 1 ; j < m ; ++j ){
                printf("(%d,%d)\n", j, i);
            }
        }
    }
    return 0;
}