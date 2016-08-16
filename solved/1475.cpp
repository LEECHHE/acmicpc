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
    char number[8]; scanf("%s", number);
    int n_set[9] = { 1,1,1,1,1,1,2,1,1 };
    int cnt[9]; memcpy(cnt, n_set, sizeof(n_set));
    int ret = 1;
    int len = (int)strlen(number);
    for( int i = 0 ; i < len ; ++i ){
        if( number[i] == '9' ) number[i] = '6';
        int& target = cnt[number[i]-'0'];
        if( target == 0 ){
            for( int j = 0 ; j < 9 ; ++j ) cnt[j] += n_set[j];
            ++ret;
        }
        --target;
    }
    printf("%d", ret);
    return 0;
}