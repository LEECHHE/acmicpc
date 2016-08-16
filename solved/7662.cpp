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
typedef pair<int, int> intPair;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        priority_queue<intPair> ascending;
        priority_queue<intPair, vector<intPair>, greater<intPair>> descending;
        bool isRemoved[1000000] = { false };
        int k; scanf("%d",&k);
        int idx = 0;
        int removed = 0;
        while(k--){
            char op[2]; int n; scanf("%s%d",op,&n);
            if( op[0] =='I' ){
                ascending.push(make_pair(n, idx));
                descending.push(make_pair(n, idx));
                ++idx;
            }
            else{
                if( idx == removed ) continue;
                if( n > 0 ){
                    while(isRemoved[ascending.top().second]) ascending.pop();
                    if( ascending.empty() ) continue;
                    isRemoved[ascending.top().second] = true;
                    ++removed;
                }
                else{
                    while(isRemoved[descending.top().second]) descending.pop();
                    if( descending.empty() ) continue;
                    isRemoved[descending.top().second] = true;
                    ++removed;
                }
            }
        }
        if( idx == removed ){
            printf("EMPTY\n");
        }
        else{
            while(isRemoved[descending.top().second]) descending.pop();
            while(isRemoved[ascending.top().second]) ascending.pop();
            printf("%d %d\n", ascending.top().first, descending.top().first);
        }
    }
    return 0;
}