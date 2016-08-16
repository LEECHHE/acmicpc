#include <cstdio>
using namespace std;

int main(){
    int cnt[201] = { 0 };
    int n; scanf("%d", &n);
    while(n--){
        int t; scanf("%d", &t);
        cnt[t+100]++;
    }
    int t; scanf("%d", &t);
    printf("%d", cnt[t+100]);
    return 0;
}