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
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while(n--){
        int t; scanf("%d",&t);
        if( left.size() <= right.size() ){
            left.push(t);
        }
        else{
            right.push(t);
        }
        
        while(!right.empty() && left.top() > right.top() ){
            int a = left.top();
            int b = right.top();
            left.pop();
            right.pop();
            left.push(b);
            right.push(a);
        }
        printf("%d\n", left.top());
    }
    return 0;
}