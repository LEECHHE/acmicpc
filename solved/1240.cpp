#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> intPair;
vector<intPair> adj[1001];
int depth[1001] = { 0, 1};
intPair parent[1001];
void labeling(int n, int d){
    depth[n] = d;
    for( auto child : adj[n] ){
        if (depth[child.first] == 0) {
            parent[child.first].first = n;
            parent[child.first].second = child.second;
            labeling(child.first, d+1);
        }
    }
}
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 1 ; i < n ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    labeling(1, 1);
    for( int i = 0 ; i < m ; ++i ){
        int n1, n2; scanf("%d%d",&n1,&n2);
        if (depth[n1] < depth[n2]) {
            swap(n1, n2);
        }
        int ret = 0;
        while (depth[n1] > depth[n2]) {
            ret += parent[n1].second;
            n1 = parent[n1].first;
        }
        while (n1 != n2) {
            ret += parent[n1].second+parent[n2].second;
            n1 = parent[n1].first; n2 = parent[n2].first;
        }
        printf("%d\n", ret);
    }
    return 0;
}