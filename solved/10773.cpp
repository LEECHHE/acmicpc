#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> seq;
    long long ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        if( t == 0 ){
            ret -= seq.back();
            seq.pop_back();
        }
        else{
            ret += t;
            seq.push_back(t);
        }
    }
    printf("%lld",ret);
    return 0;
}