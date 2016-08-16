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
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d%d",&n,&m);
        vector<int> A,B;
        for( int i = 0 ; i < n ; ++ i ){
            int t; scanf("%d",&t);
            A.push_back(t);
        }
        for( int i = 0 ; i < m ; ++ i ){
            int t; scanf("%d",&t);
            B.push_back(t);
        }
//        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int ret = 0;
        for( auto it = A.begin() ;it != A.end();++it ){
//            if( it != A.begin() && *it == *(it-1)) continue;
            ret += (upper_bound(B.begin(), B.end(), *it-1) - B.begin());
        }
        printf("%d\n",ret);
    }
    return 0;
}