#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int value(char c){
    if( c == 'H' ){
        return 1;
    }
    else if( c=='O'){
        return 16;
    }
    else if( c == 'C'){
        return 12;
    }
    else{
        return c;
    }
}
int main(){
    int ret = 0;
    char seq[105]; scanf("%s", seq);
    int len = (int)strlen(seq);
    int pos = 0;
    stack<int> s;
    while( pos < len ){
        while( pos < len && seq[pos] != ')' ){
            if( seq[pos] >= '0' && seq[pos] <= '9' ){
                int t = s.top();
                s.pop();
                s.push(t*(seq[pos]-'0'));
            }
            else{
                s.push(value(seq[pos]));
            }
//            printf("push %d\n", s.top());
            ++pos;
        }
        if( pos >= len ) break;
        int v = 0;
        while(s.top()!='('){
            v += s.top();
            s.pop();
        }
        s.pop();
        s.push(v);
        ++pos;
    }
    while(!s.empty()){
        ret += s.top();
        s.pop();
    }
    printf("%d",ret);
    return 0;
}