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
    int n,l; scanf("%d%d",&n,&l);
    vector< pair<int, intPair> > traffic;
    for( int i = 0 ; i < n ; ++i ){
        int d,r,g; scanf("%d%d%d",&d,&r,&g);
        traffic.push_back(make_pair(d, make_pair(r, g)));
    }
    traffic.push_back(make_pair(l, make_pair(0, 0)));
    int ret = traffic[0].first;
    int len = (int)traffic.size();
    for( int i = 0 ; i < len-1 ; ++i ){
        int cycle = traffic[i].second.first + traffic[i].second.second;
        if( ret % cycle <= traffic[i].second.first ){
            ret += traffic[i].second.first - ret % cycle;
        }
        ret += traffic[i+1].first - traffic[i].first;
    }
    printf("%d", ret);
    return 0;
}