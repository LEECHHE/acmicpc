#include <cstdio>
#include <queue>
using namespace std;
int visited[100001] = { 0 };
const int INF = 100000;
int main(){
    int n,k; scanf("%d%d",&n,&k);
    if( n == k ){
        printf("0");
        return 0;
    }
    for( int i = 0 ; i <= 100000 ; ++i ) visited[i] = INF;
    queue<int> q; q.push(n);
    visited[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        int cost = visited[cur];
        q.pop();
        
        if( cur != 0 && visited[cur-1] > cost+1 ){
            visited[cur-1] = cost+1;
            q.push(cur-1);
        }
        if( cur != INF && visited[cur+1] > cost+1 ){
            visited[cur+1] = cost+1;
            q.push(cur+1);
        }
        if( cur*2 <= INF && visited[cur*2] > cost+1 ){
            visited[cur*2] = cost+1;
            q.push(cur*2);
        }
    }
    printf("%d",visited[k]);
    return 0;
}