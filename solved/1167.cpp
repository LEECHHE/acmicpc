#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> intPair;
vector<intPair> child[100001];
bool visited[100001];
int ret;
int postorder(int cur){
    vector<int> diameter;
    for( auto ch : child[cur] ){
        if(!visited[ch.first]){
            visited[ch.first] = true;
            diameter.push_back(ch.second+postorder(ch.first));
        }
    }
    if( diameter.empty() ) return 0;
    sort(diameter.begin(),diameter.end());
    if( diameter.size() > 1 ) ret = max(ret, diameter.back() + *(diameter.end()-2));
    ret = max( ret, diameter.back() );
    return diameter.back();
}
int main(){
    int n; scanf("%d",&n);
    int parent[100001] = { 0 };
    for( int i = 0 ; i < n ; ++i ){
        int a; scanf("%d",&a);
        while(1){
            int b; scanf("%d", &b);
            if( b < 0 ) break;
            int c; scanf("%d",&c);
            child[a].push_back(make_pair(b, c));
            parent[b] = a;
        }
    }
    ret = 0;
    visited[1] = true;
    postorder(1);
    printf("%d", ret);
    return 0;
}