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
char img[65][65];
string quad(int sz, int x, int y){
    string res[4];
    if( sz == 1 ){
        return img[x][y] == '0' ? "0" : "1";
    }
    if( sz > 1 ){
        int dist = sz/2;
        res[0] = quad(dist, x, y);
        res[1] = quad(dist, x, y+dist );
        res[2] = quad(dist, x+dist, y);
        res[3] = quad(dist, x+dist, y+dist);
    }
    
    if( res[0].length() == 1 && ( res[0].compare(res[1]) == 0 && res[1].compare(res[2]) == 0 && res[2].compare(res[3]) == 0))
        return res[0];
    else
        return "("+res[0]+res[1]+res[2]+res[3]+")";
}
int main(){
    int t; scanf("%d",&t);
    for( int i= 0 ; i < t ; ++i ){
        scanf("%s", img[i] );
    }
    string ret = quad(t,0,0);
//    if( ret.length() == 1 ) ret = "("+ret+")";
    printf("%s", ret.c_str());
    return 0;
}