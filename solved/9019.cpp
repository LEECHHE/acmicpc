#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef pair<bool, bool> boolPair;
int L(int n){
    return (n%1000)*10+n/1000;
}
int R(int n){
    return (n%10)*1000+n/10;
}
int D(int n){
    return (2*n)%10000;
}
int S(int n){
    return n == 0 ? 9999 : n-1;
}
int process(char c, int n){
    if( c == 'L')
        return L(n);
    else if( c == 'R')
        return R(n);
    else if( c == 'D')
        return D(n);
    else
        return S(n);
}
char op[] = "DSLR";

int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int a,b; scanf("%d%d",&a,&b);
        bool visited[10001] = { false };        //isVisited, direction
        int parent[10001] = { 0 };
        char operations[10001] = { 0 };
        queue<int> q;
        q.push(a);
        visited[a] = true;
        bool hasFound = false;
        while (!hasFound && !q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 4 ; ++i) {
                int next = process(op[i], cur);
                if(!visited[next]){
                    visited[next] = true;
                    parent[next] = cur;
                    operations[next] = op[i];
                    if( next == b ){
                        hasFound = true;
                        break;
                    }
                    q.push(next);
                }
            }
        }
        
        stack<char> ans;
        while (a!=b) {
            ans.push(operations[b]);
            b = parent[b];
        }
        while (!ans.empty()) {
            printf("%c",ans.top());
            ans.pop();
        }
        printf("\n");
    }
    return 0;
}