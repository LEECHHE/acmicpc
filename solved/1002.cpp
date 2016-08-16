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

long long pow2(long long n){
    return n*n;
}
int main(){
    int n;
    long long x1, y1, r1, x2, y2, r2;
    long long sqrt_distance;
    
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1==x2 && y1==y2 && r1==r2){
            cout << -1 << endl;
            continue;
        }
        if( r2 > r1 ){
            //항상 r1이 큼.
            swap(x1,x2);
            swap(y1,y2);
            swap(r1,r2);
        }
        sqrt_distance = pow2(x1-x2) + pow2(y1-y2);  //d^2
        if( pow2(r1+r2) == sqrt_distance || pow2(r1-r2) == sqrt_distance ) cout << 1 << endl;
        else if( pow2(r1+r2) < sqrt_distance || pow2(r1-r2) > sqrt_distance ) cout << 0 << endl;
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}