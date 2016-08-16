#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;
//const int INF = 987654321;

stack<int> s;
void popValues(int& value){
    while( !s.empty() && s.top() > 0 ){
        value += s.top();
        s.pop();
    }
}
void printTop(int i){
    printf("%d th loop - ", i);
    if (s.empty()) printf("stack empty\n");
    else printf("%d on the top\n", s.top());
}
int main(){

    char brackets[31]; scanf("%s", brackets);
    int len = (int)strlen(brackets);
    bool success = true;
    for( int i = 0 ; i < len ; ++i){
        char current = brackets[i];
        if( current == '(' ) {
            s.push(-1);
        }
        else if( current == ')'){
            int top_value = 0;

            popValues(top_value);
            
            // '(' 가 없음.
            if( s.empty() ){
                success = false;
                break;
            }
            
            if( s.top() == -1 ){
                s.pop();
                
                if( top_value == 0 ) top_value = 1;
                
                top_value *= 2;

                popValues(top_value);
                s.push(top_value);

            }
            else{
                //'(' 가 없음
                success = false;
                break;
            }
        }
        else if( current == '[' ){
            s.push(-2);
        }
        else if( current == ']' ){
            // '[' 가 없음.
            int top_value = 0;

            popValues(top_value);
            
            if( s.empty() ){
                success = false;
                break;
            }
            
            if( s.top() == -2 ){
                s.pop();
                if( top_value == 0 ) top_value = 1;
                top_value *= 3;

                popValues(top_value);
                s.push(top_value);
            }
            else{
                //'[' 가 없음
                success = false;
                break;
            }
        }
    }
    if( s.size() != 1 || s.top() < 0 ) success = false;
    
    if( !success ) printf("0");
    else printf("%d", s.top());
    return 0;
}