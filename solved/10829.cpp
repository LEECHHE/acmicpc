#include <cstdio>
#include <stack>
using namespace std;
int main(){
    long long n; scanf("%lld",&n);
    stack<bool> s;
    while(n){
        s.push(n%2);
        n/=2;
    }
    while(!s.empty()){
        printf("%d",s.top());
        s.pop();
    }
    return 0;
}