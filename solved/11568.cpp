#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> seq(n);
    for( int i = 0 ; i < n ; ++i ) scanf("%d",&seq[i]);
    vector<int> lis; lis.push_back(seq[0]);
    int idx = 0;
    for( int i = 1 ; i < n ; ++i ){
        if( lis[idx] < seq[i] ){
            lis.push_back(seq[i]);
            ++idx;
            continue;
        }
        auto it = (int)(lower_bound(lis.begin(), lis.begin()+idx+1, seq[i])-lis.begin());
        lis[it] = seq[i];
    }
    printf("%d", (int)lis.size());
    return 0;
}