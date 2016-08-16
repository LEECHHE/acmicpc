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
int white = 0;
int blue = 0;
int n;
int paper[130][130];
string divide(int x,int y, int size){
    if( size == 1 ){
        return paper[x][y] ? "B" : "W";
    }
    int len = size/2;
    string papers[4] = {
        divide(x, y, len),
        divide(x, y+len, len),
        divide(x+len, y, len),
        divide(x+len, y+len, len)
    };
    if( papers[0].compare(papers[1]) == 0 && papers[1].compare(papers[2]) == 0 && papers[2].compare(papers[3]) == 0 ){
        if(papers[0].length() == 1) return papers[0];
    }
//        return "(" +papers[0]+papers[1]+papers[2]+papers[3] +")";
    return papers[0]+papers[1]+papers[2]+papers[3];
}
int main(){
    scanf("%d",&n);
    
    for( int i = 0 ;i<n;++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d",&paper[i][j]);
        }
    }
    string ret = divide(0, 0, n);
    int len = (int)ret.length();
//    printf("%s\n", ret.c_str());
    for( int i = 0 ; i < len ; ++i ){
//        if( ret[i] == 'C' || ret[i] == ')' ) continue;
        ret[i] == 'W'?++white:++blue;
    }
    printf("%d\n%d", white, blue);
    return 0;
}