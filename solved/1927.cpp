#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#define INF 987654321
#define MAX_V 800
using namespace std;

int main(){
    int n; scanf("%d",&n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for( int i = 0 ; i < n ; ++i ){
        int x; scanf("%d", &x);
        if( x > 0 ) pq.push(x);
        else {
            if( pq.empty() ) printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
    return 0;
}