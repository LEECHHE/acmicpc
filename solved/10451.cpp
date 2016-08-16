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
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d", &n);
        int next[1001];
        for( int i = 1 ; i <= n ; ++i ){
            scanf("%d", &next[i]);
        }
        int ret = 0;
        int cnt = n;
        bool visited[1001] = { 1,0 };
        for( int current = 1; ; ){
            if(visited[current]){
                ++ret;
//                printf("cycle ends:%d\n", current);
                if(cnt == 0 ) break;
                while(visited[current]){
                    current += 1;
                    if( current > n ) current %= n;
                }
            }
            visited[current] = true;
            current = next[current];
            --cnt;
        }
        printf("%d\n",ret);
    }
    return 0;
}