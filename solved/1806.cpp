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
    int n, s; scanf("%d%d", &n, &s);
    int current = 0;
    int ret = 100000;
    queue<int> numbers;
    while(n--){
        int temp; scanf("%d",&temp);
        numbers.push(temp);
        current += temp;
        if( current >= s ){
            while(!numbers.empty()){
                ret = min( ret, (int)numbers.size() );
                
                int head = numbers.front();
                numbers.pop();
                
                current -= head;
                if( current < s ) break;
            }
        }
    }
    if( ret >= 100000 ) ret = 0;
    printf("%d", ret);
    return 0;
}