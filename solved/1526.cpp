#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> shom;
void dfs(int cur, int step){
    if( step == 0 ){
        shom.push_back(cur);
        return;
    }
    dfs(cur*10+4, step-1);
    dfs(cur*10+7, step-1);
}
int main(){
    int n; scanf("%d",&n);
    for( int step = 0 ; step < 6 ; ++step ){
        dfs(4, step);
        dfs(7, step);
    }
    sort(shom.begin(), shom.end());
    int idx = lower_bound(shom.begin(), shom.end(), n)-shom.begin();
    if ( n != shom[idx] ) --idx;
    printf("%d",shom[idx]);
    return 0;
}