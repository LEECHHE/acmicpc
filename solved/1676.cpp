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
    vector<int> pow5;
    long p = 1;
    while( p <= 2000000000 ){
        pow5.push_back((int)p);
        p *=5 ;
    }
    int n; scanf("%d",&n);
    int ret = 0;
    int idx = 1;
    while(n >= pow5[idx]){
        ret += n / pow5[idx];
        idx++;
    }
    printf("%d",ret);
    return 0;
}