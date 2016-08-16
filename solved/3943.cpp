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
typedef pair<int,int> intPair;
typedef unsigned long long ull;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int ret = 1;
        for( int i = 1 ; ;++i ){
            if(n == 1 ){
                printf("%d\n", ret);
                break;
            }
            ret = max(n,ret);
            n = n%2?3*n+1:n/2;
        }
    }
    return 0;
}