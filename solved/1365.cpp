#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; int seq[100000];
    vector<int> ans;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    int size = 1;
    ans.push_back(seq[0]);
    for( int i = 1 ; i < n ; ++i ){
        if(ans[size-1] < seq[i]){
            ans.push_back(seq[i]);
            ++size;
            continue;
        }
        auto it = (int)(lower_bound(ans.begin(), ans.begin()+size, seq[i])-ans.begin());
        ans[it] = seq[i];
    }
    printf("%d",n-size);
    return 0;
}