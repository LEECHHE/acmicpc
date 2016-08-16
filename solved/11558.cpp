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
        int n; scanf("%d",&n);
        int next[10001] = { 0 };
        bool visited[10001] = { false };
        for( int i = 1 ; i <= n ; ++i ){
            scanf("%d", &next[i]);
        }
        int ret = 0;
        int cnt = 1;
        int cur = 1;
        visited[cur] = true;
        while(ret == 0){
            cur = next[cur];
            if( cur == n ){
                ret = cnt;
                break;
            }
            if( visited[cur]){
                break;
            }
            visited[cur] = true;
            cnt++;
        }
        printf("%d\n", ret);
    }
    return 0;
}