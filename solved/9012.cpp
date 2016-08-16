#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int main(){
    int c; scanf("%d",&c);
    while(c--){
        char ps[51]; scanf("%s", ps);
        int len = (int)strlen(ps);
        stack<char> s;
        string ret = "YES";
        for( int i = 0 ; i < len ; ++i ){
            if( ps[i] =='('){
                s.push('(');
                continue;
            }
            else{
                if(s.empty() || s.top() == ')'){
                    ret = "NO";
                    break;
                }
                else{
                    s.pop();
                }
            }
        }
        if( !s.empty() ) ret = "NO";
        printf("%s\n", ret.c_str());
    }
    return 0;
}