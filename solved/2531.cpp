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
    int n,d,k,c; scanf("%d%d%d%d",&n,&d,&k,&c);
    int sushi[30000];
    vector<int> q(k);
    int isContained[3001] = { 0 };
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&sushi[i]);
    }
    int ret = 0;
    int len = (int)min(k,n);
    for( int i = 0 ; i < k ; ++i ){
        if(!isContained[sushi[i]]){
            ++ret;
        }
        q[i] = sushi[i];
        isContained[sushi[i]]++;
    }
    if(!isContained[c]){
        ++ret;
    }
    isContained[c]++;
    int cnt = ret;
    for( int idx = k; idx < n+k ; ++idx){
        if(--isContained[q[0]] == 0 ){
            --cnt;
        }
        q.erase(q.begin());
        q.push_back(sushi[idx%n]);
        if(isContained[sushi[idx%n]]++ == 0){
            ++cnt;
        }
        ret = max(cnt,ret);
//            printf("cnt: %d/ ",cnt);
//            for( auto s : q ){
//                printf("%d ",s);
//            }
//            printf("\n");
    }
    printf("%d",ret);
    return 0;

}