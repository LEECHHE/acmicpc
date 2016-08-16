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
    int n; scanf("%d",&n);
    int sum[3] = {0};
    int count = 0;
    while(n--){
        char amount[4]; scanf("%s", amount);
        if(amount[2] == '2') sum[1]++;
        else if(amount[0] == '1') sum[0]++;
        else sum[2]++;
    }
    int piece1 = min(sum[0], sum[2]);
    count += piece1;
    sum[0] -= piece1; sum[2] -= piece1;
    if( sum[0] == 0 && sum[2] == 0 ){
        count += sum[1] % 2 == 0 ? sum[1]/2 : sum[1]/2 + 1;
    }
    else if(sum[0] == 0){
        count += sum[1] % 2 == 0 ? sum[1]/2 : sum[1]/2 + 1;
        count += sum[2];
    }
    else if(sum[2] == 0 ){
        count += sum[1]/2;
        if(sum[1]%2){
            if( sum[0] > 1 ){
                ++count;
                sum[0] -= 2;
            }
        }
        count += (int)ceil((double)sum[0]/4);
    }
    printf("%d", count);
    return 0;
}