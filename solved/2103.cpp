#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> intPair;
vector<intPair> p;
bool cmp(const intPair& a, const intPair& b){
    if( a.second != b.second ) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        p.push_back(intPair(a,b));
    }
    sort(p.begin(), p.end());
    int ret = 0;
    for( int i = 0 ; i < p.size() ; i += 2 ){
        ret += p[i+1].second-p[i].second;
    }
    sort(p.begin(), p.end(), cmp);
    for( int i = 0 ; i < p.size() ; i += 2 ){
        ret += p[i+1].first-p[i].first;
    }
    printf("%d",ret);
    return 0;
}