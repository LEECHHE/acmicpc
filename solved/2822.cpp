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
    int n;
    vector<pair<int, int>> score;
    for( int i = 1 ; i <= 8 ; ++i ){
        scanf("%d",&n);
        score.push_back(make_pair(n, i));
    }
    sort(score.begin(), score.end());
    int sum = 0;
    vector<int> ans;
    for(int i = 3 ; i < 8;++i){
        sum += score[i].first;
        ans.push_back(score[i].second);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",sum);
    for( auto i : ans ){
        printf("%d ",i);
    }
    return 0;
}