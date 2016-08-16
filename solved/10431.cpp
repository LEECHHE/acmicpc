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
typedef pair<int, int> intPair;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int cse; scanf("%d", &cse);
        vector<int> heights;
        int ret = 0;
        for( int i = 0 ; i < 20 ; ++i ){
            int h; scanf("%d",&h);
            auto it = upper_bound(heights.begin(), heights.end(), h);
            if( it != heights.end() ){
                ret += heights.size()-(it-heights.begin());
            }
            heights.insert(it, h);
        }
        printf("%d %d\n",cse,ret);
    }
    return 0;
}