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
const int INF = (1<<31)-1;
int p10[] = {1,10,100,1000,10000};
int luck[2] = { 5, 8};
vector<int> lucky;
void dfs(int digit, int luckNumber, int idx){
    if( digit <= 0 ){
        luckNumber += luck[idx];
        lucky.push_back(luckNumber);
        return;
    }
    int curNum = luckNumber + p10[digit]*luck[idx];
    dfs(digit-1, curNum, 0);
    dfs(digit-1, curNum, 1);
}
int main(){
    int t; scanf("%d",&t);
    for( int digit = 0 ; digit <= 4 ; ++digit ){
        dfs(digit, 0, 0);
        dfs(digit, 0, 1);
    }
    sort(lucky.begin(), lucky.end());
    while(t--){
        vector<int> luckyNum(lucky);
        int k,l,m;
        int a[50],b[50],c[50];
        scanf("%d",&k);
        for( int i = 0 ; i < k ; i+=scanf("%d",&a[i]));
        scanf("%d",&l);
        for( int i = 0 ; i < l ; i+=scanf("%d",&b[i]));
        scanf("%d",&m);
        for( int i = 0 ; i < m ; i+=scanf("%d",&c[i]));
        
        int ret= 0;
        for( int i = 0 ; i < k ; ++i){
            for( int j = 0 ; j < l ; ++j ){
                for( int p = 0 ; p < m; ++p ){
                    int cur = a[i]+b[j]+c[p];
                    auto it = find(luckyNum.begin(), luckyNum.end(), cur);
                    if( it != luckyNum.end() ){
                        ++ret;
                        luckyNum.erase(it);
                    }
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}