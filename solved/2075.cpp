#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> l = vector<int>(n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&l[i]);
    }
    sort(l.begin(), l.end());
    for( int i = n ; i < n*n ; ++i ){
        int a; scanf("%d",&a);
        if( a < l[0] ) continue;
        l.insert(lower_bound(l.begin(), l.end(), a), a);
        l.erase(l.begin());
    }
    sort(l.begin(),l.end());
    printf("%d",l[0]);
    return 0;
}