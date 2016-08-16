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
int main(){
    while(1){
        int n,m; scanf("%d%d",&n,&m);
        if( n == 0 && m == 0 ) break;
        vector<int> sun;
        for( int i =0 ; i < n ; ++i ){
            int t; scanf("%d",&t);
            sun.push_back(t);
        }
        int ret = 0;
        for( int i = 0 ; i < m ; ++i ){
            int t; scanf("%d", &t);
            if( binary_search(sun.begin(), sun.end(), t) ) ret++;
        }
        printf("%d\n",ret);
    }
    return 0;
}