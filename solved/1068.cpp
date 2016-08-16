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
    vector< int > child[50];
    int root = -1;
    for( int i = 0 ; i < n ; ++i ){
        int parent; scanf("%d", &parent);
        if( parent == -1 ) root = i;
        else{
            child[parent].push_back(i);
        }
    }
    int removed; scanf("%d", &removed);
    child[removed].clear();
    queue< int > q;
    int ret = 0;
    
    q.push(root);
    while( !q.empty() ){
        int cur = q.front();
        q.pop();

        if ( cur == removed ) continue;
        if( child[cur].empty() ){
            ++ret;
        }
        for( auto node : child[cur] ){
            q.push(node);
        }
    }
    printf("%d", ret);
    return 0;
}