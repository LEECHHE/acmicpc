#include <cstdio>
#include <stack>
using namespace std;
char num[11] = "9876543210";
int n;
stack<char> s;
void dfs(int cur, int step){
    if( step == 1 ){
        --n;
        if( n < 0 ){
            s.push(num[cur]);
        }
        return;
    }
    for( int i = 11-step; i > cur ; --i ){
        dfs(i, step-1);
        if( n < 0 ){
            s.push(num[cur]);
            return;
        }
    }
}
int main(){
    int comb[10] = { 10, 45, 120, 210, 252, 210, 120, 45, 10, 1 };
    scanf("%d",&n);
    n--;
    for( int i = 0 ; i < 10 ; ++i ){
        if( n - comb[i] < 0 ){
            int len = i+1;
            for(int j = 10-len ; j >= 0 ; --j ){
                dfs(j, len);
                if(!s.empty()) break;
            }
            if(!s.empty()) break;
        }
        n -= comb[i];
    }
    if( s.empty() ) printf("-1");
    else{
        while(!s.empty()){
            printf("%c",s.top());
            s.pop();
        }
    }
    return 0;
}