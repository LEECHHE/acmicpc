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
    int t; scanf("%d", &t);
    int construct_time[1001];
    int total[1001];
    vector<int> edges[1001];
    while (t--){
        memset(construct_time, 0, sizeof(construct_time));
        memset(total, 0, sizeof(total));
        
        int n, k, w; scanf("%d%d", &n, &k);
        for( int i = 1 ; i <= n ; ++i ){
            edges[i].clear();
            total[i] = -1;
            scanf("%d", &construct_time[i]);
        }
        bool indegree[1001] = { false };
        for( int i = 0 ; i < k ; ++i ){
            int a, b; scanf("%d%d",&a,&b);
            edges[a].push_back(b);
            indegree[b] = true;
        }
        
        scanf("%d", &w);
        queue<int> que;
        for( int i = 1 ; i <= n ; ++i ){
            if(!indegree[i]){
                que.push(i);
                total[i] = construct_time[i];
            }
        }
        while(!que.empty()){
            int current = que.front();
            que.pop();

            for( auto node : edges[current] ){
                if( total[node] < total[current]+construct_time[node]){
                    total[node] = total[current]+construct_time[node];
                    que.push(node);
                }
            }
        }
        printf("%d\n",total[w]);
        
    }
    return 0;
}