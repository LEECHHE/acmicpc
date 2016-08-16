#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int a[8];
bool visited[8] = { false };
int n;
int ret = -1;
vector<int> order;
int abs(int a){
    return a < 0 ? -a : a;
}
int sum(){
    int re = 0;
    for( int i = 0 ; i < order.size()-1 ; ++i ){
        re += abs(a[order[i]]-a[order[i+1]]);
    }
    return re;
}

void ordering(int v){
    if( order.size() == n ){
        ret = max(ret, sum());
        return;
    }
    for( int i = 0 ; i < n ; ++i ){
        if(!visited[i]){
            visited[i] = true;
            order.push_back(i);
            ordering(i);
            order.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ) scanf("%d",&a[i]);
    for( int i = 0 ; i < n ; ++i ){
        visited[i] = true;
        order.push_back(i);
        ordering(i);
        visited[i] = false;
        order.pop_back();
    }
    printf("%d",ret);
    return 0;
}