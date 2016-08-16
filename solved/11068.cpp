#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
bool isParlin(int n, int b){
    stack<int> s;
    while (n>=b) {
        s.push(n%b);
        n/=b;
    }
    if( n > 0 ) s.push(n);
    char digits[25] = { 0 };
    int len = s.size();
    while (!s.empty()) {
        digits[len-s.size()] = s.top();
        s.pop();
    }
    for (int i = 0; i < len/2; ++i) {
        if( digits[i] != digits[len-i-1] ) return false;
    }
    return true;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        bool ret = false;
        for( int base = 2 ; base <= 64 ; ++base ){
            ret = isParlin(n, base);
            if (ret) break;
        }
        printf("%d\n",ret);
    }
    return 0;
}