#include <cstdio>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> pq;
    int n; scanf("%d",&n);
    while(n--){
        int t; scanf("%d",&t);
        if (t > 0)
            pq.push(t);
        else{
            if( pq.empty()) pq.push(0);
            printf("%d\n",pq.top());
            pq.pop();
        }
    }
    return 0;
}