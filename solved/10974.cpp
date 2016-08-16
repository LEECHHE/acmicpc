#include <cstdio>
#include <vector>
using namespace std;
vector<int> l;
int n;
int idx[8] = { 1 };
void dfs(int visited){
    if(l.size() == n){
        for( auto a : l ){
            printf("%d ", a);
        }
        printf("\n");
        return;
    }
    for( int i = 0 ; i < n ; ++i ){
        if( (visited & idx[i]) == 0 ){
            l.push_back(i+1);
            dfs(visited|idx[i]);
            l.pop_back();
        }
    }
}
int main(){
    for( int i = 1 ; i < 8 ; ++i ){
        idx[i] = idx[i-1]<<1;
    }
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        l.push_back(i+1);
        dfs(idx[i]);
        l.pop_back();
    }
    return 0;
}