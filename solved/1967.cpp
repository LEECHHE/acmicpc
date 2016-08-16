#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> intPair;
vector<intPair> child[10001];
int ret;
int postorder(int cur){
    vector<int> diameter;
    for( auto ch : child[cur] ){
        diameter.push_back(ch.second+postorder(ch.first));
    }
    if( diameter.empty() ) return 0;
    sort(diameter.begin(),diameter.end());
    if( diameter.size() > 1 ) ret = max(ret, diameter.back() + *(diameter.end()-2));
    ret = max( ret, diameter.back() );
    return diameter.back();
}
int main(){
    int n; scanf("%d",&n);
    for( int i = 1 ; i < n ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        child[a].push_back(make_pair(b, c));
    }
    ret = 0;
    postorder(1);
    printf("%d", ret);
    return 0;
}