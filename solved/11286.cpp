#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, bool> intPair;
struct compare{
    bool operator()(const intPair& a, const intPair& b){
        if( a.first != b.first ) return a > b;
        else return a.second;
        return false;
    }
};
int main(){
    priority_queue<intPair, vector<intPair>, compare> pq;
    int n; scanf("%d",&n);
    while(n--){
        int t; scanf("%d",&t);
        if (t != 0){
            bool sign = t > 0;
            if(!sign) t *= -1;
            pq.push(make_pair(t,sign));
        }
        else{
            if( pq.empty()) pq.push(make_pair(0,true));
            int v = pq.top().second ? pq.top().first : -pq.top().first;
            printf("%d\n",v);
            pq.pop();
        }
    }
    return 0;
}