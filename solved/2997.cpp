#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> series;
    for( int i = 0 ; i < 3 ; ++i ){
        int t; scanf("%d",&t);
        series.push_back(t);
    }
    sort(series.begin(), series.end());
    int d = min(series[2]-series[1], series[1]-series[0]);
    int ans = 10000;
    if( d == 0 ){
        ans = 0;
    }
    else{
        for( int i = 0 ; i < 2 ; ++i ){
            if( series[i+1] != series[i] + d ){
                ans = series[i]+d;
                break;
            }
        }
        if( ans >= 10000 ){
            ans = series[2] + d;
        }
    }
    printf("%d", ans);
    return 0;
}