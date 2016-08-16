#include <cstdio>
using namespace std;
int card[20000001] = { 0 };
const int pivot = 10000000;
int main(){
    int n; scanf("%d",&n);
    while(n--){
        int t; scanf("%d",&t);
        card[t+pivot]++;
    }
    int m; scanf("%d",&m);
    while(m--){
        int t; scanf("%d",&t);
        printf("%d ",card[t+pivot]);
    }
    return 0;
}