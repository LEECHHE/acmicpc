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
    int n; scanf("%d",&n);
    vector<pair< int,int> > meeting;
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d", &a,&b);
        meeting.push_back(make_pair(b, a));
    }
    sort(meeting.begin(), meeting.end());
    int currentMax = -1;
    int ret = 0;
    for( auto m : meeting ){
//        printf("(%d,%d)\n", m.first, m.second);
        if( currentMax <= m.second ){
            currentMax = m.first;
            ++ret;
        }
    }
    printf("%d",ret);
    return 0;
}