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
    int a,b; scanf("%d%d",&a,&b);
    for( int step = 0 ; step < 9 ; ++step ){
        dfs(4, step);
        dfs(7, step);
    }
    sort(shom.begin(), shom.end());

    int left = lower_bound(shom.begin(), shom.end(), a)-shom.begin();
    int right = lower_bound(shom.begin(), shom.end(), b)-shom.begin();
    if ( b != shom[right] ) --right;
    printf("%d",right-left+1);
    return 0;
}