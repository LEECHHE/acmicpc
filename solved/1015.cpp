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
bool pairCompare(const intPair& firstElem, const intPair& secondElem) {
    if (firstElem.first < secondElem.first) return true;
    else{
        if(firstElem.first < secondElem.first) return false;
        
        if( firstElem.first == secondElem.first ){
            return firstElem.second < secondElem.second;
        }
    }
    return false;
}
int main(){
    int n; scanf("%d", &n);
    vector<intPair> seq;
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        seq.push_back(make_pair(t,i));
    }
    sort(seq.begin(), seq.end(), pairCompare);
    int ans[1001];
    for( int i = 0 ; i < n ; ++i ){
        ans[seq[i].second] = i;
    }
    for( int i =0  ; i < n ; ++i ){
        printf("%d ", ans[i]);
    }
    return 0;
}