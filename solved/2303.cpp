#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> intPair;
int main(){
    priority_queue<intPair> pq;
    int n; scanf("%d",&n);
    for( int idx = 1 ; idx <= n ; ++idx){
        int seq[5]; for( int j = 0 ; j < 5 ; j += scanf("%d", &seq[j]));
        int value = -1;
        for( int i = 0 ; i < 3; ++i ){
            for( int j = i+1 ; j < 4; ++j ){
                for( int k = j+1; k < 5 ; ++k ){
                    value = max((seq[i]+seq[j]+seq[k])%10, value);
                }
            }
        }
        pq.push(make_pair(value, idx));
    }
    int value = pq.top().first;
    int winner = pq.top().second;
    pq.pop();
    while(!pq.empty() && pq.top().first == value){
        winner = max(pq.top().second, winner);
        pq.pop();
    }
    printf("%d", winner);
    return 0;
}