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
int cnt[4];
int main(){
    int ret = 0;
    for( int i = 0 ; i < 4 ; ++i){
        scanf("%d",&cnt[i]);
    }
    if( cnt[0] > 0 || cnt[1] > 0 ){
        ret += cnt[0];  //FF FF.....


        bool startWithSlow = false;
        if( cnt[1] > 0 ){
            cnt[1]--;           //FS SS SS ...
            ret += cnt[3]+1;
            startWithSlow = true;
        }
        int _min = min(cnt[1], cnt[2]);
        ret += _min * 2;
        cnt[1] -= _min;
        cnt[2] -= _min;
        
        if( startWithSlow ){
            //SS SF FS
            if( cnt[2] > 0 ) ret++;
        }
        else {
            //FF FS SF ...
            if( cnt[1] > 0 ) ret++;
        }
    }
    else{
        ret += cnt[3] + (cnt[2]>0);
    }
    printf("%d",ret);
    return 0;
}