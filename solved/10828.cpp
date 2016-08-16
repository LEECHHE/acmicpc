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
#include <cstring>
using namespace std;
//const int INF = 987654321;
stack<int> s;
void process(char *op){
    if ( !strcmp(op, "push") ){
        int x; scanf("%d", &x);
        s.push(x);
    }
    else if( !strcmp(op, "pop")){
        if(s.empty())
            printf("-1\n");
        else{
            printf("%d\n", s.top());
            s.pop();
        }
    }
    else if( !strcmp(op, "size")){
        printf("%ld\n", s.size());
    }
    else if ( !strcmp(op, "empty")){
        int ret = s.empty() ? 1 : 0;
        printf("%d\n", ret);
    }
    else if( !strcmp(op, "top")){
        if(s.empty())
            printf("-1\n");
        else{
            printf("%d\n", s.top());
        }
    }
    return;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        char op[6];
        scanf("%s", op);
        process(op);
    }
    return 0;
}