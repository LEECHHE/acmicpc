#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int cur; scanf("%d",&cur);
    priority_queue<int > pq;
    for( int i = 1 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        pq.push(t);
    }
    int ret=0;
    while(!pq.empty() && cur <= pq.top()){
        int t = pq.top();
        pq.pop();
        
        while( cur <= t && t >= pq.top() ){
            ++ret;
            ++cur;
            --t;
        }
        pq.push(t);
    }
    printf("%d",ret);
    return 0;
}