#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, bool> iPair;
int main(){
    vector<iPair> l;
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        l.push_back(iPair(a,true));
        l.push_back(iPair(b,false));
    }
    sort(l.begin(), l.end());
    int ret = 1;
    int cur = 0;
    for ( auto l1 : l ){
        if( l1.second ){
            ++cur;
        }
        else{
            ret = max(ret,cur);
            --cur;
        }
    }
    printf("%d",ret);
    return 0;
}