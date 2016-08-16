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
    int t; scanf("%d",&t);
    
    while(t--){
        int n, target_idx; scanf("%d%d", &n, &target_idx);
        int count = 0;
        priority_queue< int , vector<int> , less<int> > pq;
        queue< pair<int, int> > que;    //idx, priority
        
        for( int i = 0 ; i < n ; ++i ){
            int priority; scanf("%d", &priority);
            que.push(make_pair(i, priority));
            pq.push(priority);
        }
        
        while(!que.empty() ){
            pair< int, int > current = que.front();
            if( current.second < pq.top() ){
                que.push(make_pair(current.first, current.second));
            }
            else{
                //print out
//                printf("%d is printed out. priority: %d\n", current.first, current.second);
                pq.pop();
                ++count;
                if( current.first == target_idx ) break;
            }
            que.pop();
        }
        printf("%d\n", count);
    }
    
    return 0;
}