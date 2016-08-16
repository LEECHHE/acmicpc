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
typedef pair<int, string> intPair;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        vector<intPair> list;
        int n; scanf("%d",&n);
        for( int i = 0 ; i < n ; ++i ){
            char name[21]; int l; scanf("%s%d",name,&l);
            list.push_back(make_pair(l, string(name)));
        }
        sort(list.begin(), list.end());
        printf("%s\n", list.back().second.c_str());
    }
    return 0;
}