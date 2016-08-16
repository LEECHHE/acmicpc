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

intPair toMinutes(int d, int s, int e){
    int start = (d-1)*1440 + (s/100)*60 + (s%100);
    int end = (d-1)*1440+ (e/100)*60 + (e%100);
    return make_pair(end, start);
}
int main(){
    int t; scanf("%d",&t);
    for( int cse = 1 ; cse <= t ; ++cse){
        int k; scanf("%d",&k);
        vector<intPair> times;
        for( int i = 0 ; i < k ; ++i ){
            int d,s,e; scanf("%d%d%d", &d,&s,&e);
            times.push_back(toMinutes(d, s, e));
        }
        sort(times.begin(), times.end());
        intPair cur = times[0];
        int ret = 1;
        for( int i = 1 ; i < k ; ++i ){
            if( cur.first <= times[i].second ){
                ++ret;
                cur = times[i];
            }
        }
        printf("Scenario #%d:\n%d\n\n", cse, ret);
        
    }
    return 0;
}