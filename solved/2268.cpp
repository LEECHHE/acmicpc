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
using namespace std;
const int MAX = 2000000;
int seq[1000001] = { 0 };
int tree[2000001] = { 0 };
void update(int idx, int val){
    while( idx <= MAX ){
        tree[idx] += val;
        idx += (idx & -idx);
    }
    return;
}
int read(int idx){
    int ret = 0;
    while( idx > 0 ){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    while(m--){
        int op, i, j; scanf("%d%d%d", &op, &i, &j);
        if( !op ){
            int param1, param2;
            if( i < j ){
                param1 = i; param2 = j;
            }
            else{
                param1 = j; param2 = i;
            }
            printf("%d\n", read(param2) - read(param1-1) );
        }
        else{
            int before = seq[i];
            update( i, j - before );
            seq[i] = j;
        }
    }
    return 0;
}