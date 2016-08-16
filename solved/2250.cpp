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
typedef unsigned long long ull;
typedef struct node{
    int child[2];
    intPair width;
    int level;
}node;
int parent[10001] = { 0 };
node tree[10001];
intPair width[1000];
int maxLevel = -1;
int dfs(int cur, int level){
    tree[cur].level = level;
    maxLevel = max(maxLevel, level);
    if ( tree[cur].child[0] < 0 && tree[cur].child[1] < 0 ){
        return 1;
    }
    if( tree[cur].child[0] > 0 ){
        tree[cur].width.first = -dfs(tree[cur].child[0], level+1);
    }
    if( tree[cur].child[1] > 0 ){
        tree[cur].width.second = dfs(tree[cur].child[1], level+1);
    }
//    printf("node :%d, width: %d,%d, level %d\n", cur, tree[cur].width.first, tree[cur].width.second, level);
    return tree[cur].width.second-tree[cur].width.first+1;
}
int main(){
    int n; scanf("%d",&n);
    int root = 0;
    for( int i = 0 ; i < n ; ++i ){
        int p, c1, c2; scanf("%d%d%d",&p,&c1,&c2);
        tree[p].child[0] = c1;
        tree[p].child[1] = c2;
        if( c1 > 0 ) parent[c1] = p;
        if( c2 > 0 ) parent[c2] = p;
        root = p;
    }
    while(parent[root]) root = parent[root];
    
    dfs(root, 1);
    
    intPair limit = make_pair((1<<31)-1, 1<<31);
    for( int i = 1 ; i <= maxLevel ; ++i ) width[i] = limit;
    
    queue<intPair> q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        intPair cur = q.front();
        q.pop();
        
        int leftChild = tree[cur.first].child[0];
        int rightChild = tree[cur.first].child[1];
        int left_pos = cur.second - tree[leftChild].width.second -1;
        int right_pos = cur.second - tree[rightChild].width.first + 1;
        
        int curLevel = tree[cur.first].level;
        width[curLevel].first = min(width[curLevel].first,cur.second);
        width[curLevel].second = max(width[curLevel].second,cur.second);
        
        if(leftChild>0) q.push(make_pair(leftChild, left_pos));
        if(rightChild>0) q.push(make_pair(rightChild, right_pos));
    }
    int retLevel = 0, retWidth = 0;
    for( int i = 1 ; i <= maxLevel ; ++i ){
        int curWidth =width[i].second-width[i].first+1;
//        printf("level:%d(%d,%d)\n",i,width[i].first,width[i].second);
        if( curWidth > retWidth ){
            retLevel = i;
            retWidth = curWidth;
        }
    }
    printf("%d %d", retLevel, retWidth );
    return 0;
}