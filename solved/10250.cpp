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
    int t; scanf("%d",&t);
    while(t--){
        int h,w,n; scanf("%d%d%d", &h, &w, &n);
        int floor = n % h;
        int room = n / h;
        if( floor == 0 ){
            floor += h;
            room -= 1;
        }
        printf("%d\n", 100*(floor) + room+1);
    }
    return 0;
}