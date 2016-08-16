#include <cstdio>
using namespace std;
int height[500001] = { 100000001 };
int sendto[500001] = { 0 };
int main(){
    int n; scanf("%d",&n);
    for (int i = 1; i <= n ; ++i) {
        scanf("%d",&height[i]);
        int cur = i-1;
        while (height[cur] < height[i]) {
            cur = sendto[cur];
        }
        sendto[i] = cur;
        printf("%d ",sendto[i]);
    }
    return 0;
}