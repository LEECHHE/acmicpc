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
typedef struct cntry{
    int medal[3];
    int idx;
} cntry;
bool cmp(const cntry& a, const cntry& b){
    if( a.medal[0] == b.medal[0] ){
        if( a.medal[1] == b.medal[1] ){
            return a.medal[2] > b.medal[2];
        }
        else{
            return a.medal[1] > b.medal[1];
        }
    }
    else{
        return a.medal[0] > b.medal[0];
    }
}
int main(){
    int n,k; scanf("%d%d",&n,&k);
    vector<cntry> record;
    for( int i = 0 ; i < n ; ++i ){
        cntry c; scanf("%d%d%d%d",&c.idx,&c.medal[0],&c.medal[1],&c.medal[2]);
        record.push_back(c);
    }
    sort(record.begin(), record.end(), cmp);
    int ret = 0;
    int cur_rank = 1;
    int same_cnt = 1;
    if( record[0].idx == k ){
        ret = 1;
    }
    else{
        for( int i = 1 ; i < n ; ++i ){
            if( record[i-1].medal[0] == record[i].medal[0] &&
               record[i-1].medal[1] == record[i].medal[1] &&
               record[i-1].medal[2] == record[i].medal[2] ){
                same_cnt++;
            }
            else{
                cur_rank += same_cnt;
                same_cnt = 1;
            }
            if( record[i].idx == k ){
                ret = cur_rank;
                break;
            }
        }
    }
    printf("%d", ret);
    return 0;
}