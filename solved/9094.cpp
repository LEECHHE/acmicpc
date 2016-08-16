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
    for( int i = 0 ; i < t ; ++i ){
        int n, m; scanf("%d%d",&n,&m);
        int count = 0;
        for( int a = 1 ; a < n - 1 ; ++a ){
            for ( int b = a+1; b < n ; ++b){
                if(  (a*a + b*b+m) % (a*b) > 0 ) continue;
                ++count;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}