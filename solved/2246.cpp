#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> intPair;
bool cmp(const intPair& a, const intPair& b){
    if( a.first == b.first ){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main(){
    int n; scanf("%d",&n);
    vector<intPair> cd(n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d%d",&cd[i].first,&cd[i].second);
    }
    sort(cd.begin(), cd.end(), cmp);
    
    int cost = cd[0].second;
    int dist = cd[0].first;
    int ret = 1;
    for( int i = 1 ; i < n ; ++i ){
        if( dist == cd[i].first ) continue;
        if ( cost > cd[i].second ) {
            cost = cd[i].second;
            dist = cd[i].first;
            ++ret;
        }
    }
    printf("%d",ret);
    return 0;
}