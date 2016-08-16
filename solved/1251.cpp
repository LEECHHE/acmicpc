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
    priority_queue<string, vector<string>, greater<string>> pq;
    char c[51]; scanf("%s", c);
    string orgin(c);
    int len = (int)orgin.length();
    for( int i = 1 ; i < len-1 ; ++i ){
        for( int j = i+1 ; j < len ; ++j ){
            string temp(orgin);
            reverse(temp.begin(), temp.begin()+i);
            reverse(temp.begin()+i, temp.begin()+j);
            reverse(temp.begin()+j, temp.end());
            pq.push(temp);
//            printf("push %s(%d,%d)\n", temp.c_str(), i, j);
        }
    }
    printf("%s", pq.top().c_str());
    return 0;
}