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
const long long INF = (1<<31)-1;
int main(){
    int a,b,m; scanf("%d%d%d",&a,&b,&m);
    long long powA[33] = { 1 , a};
    for( int i = 2 ; powA[i-1] < INF ; ++i){
        powA[i] = powA[i-1]*a;
    }
    int b10 = 0;
    for( int i = m-1 ; i >= 0 ; --i ){
        int t; scanf("%d",&t);
        b10 += t*powA[i];
    }
    stack<int> s;
    while( b10 ){
        s.push(b10%b);
        b10 /= b;
    }
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}