#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    char adj[50][51];
    bool fr[50][50] = { false };
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", adj[i]);
    }
    
    for( int i = 0 ; i < n ; ++i ){
        for( int j =0  ; j < n ; ++j ){
            for (int k = 0 ; k < n ; ++k) {
                fr[i][j] = adj[i][j]=='Y' || (adj[i][k] == 'Y' && adj[k][j] == 'Y');
                if( fr[i][j] ) break;
            }
        }
    }
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int cnt = 0;
        for( int j = 0 ; j < n ; ++j ){
            if( i == j ) continue;
            if( fr[i][j] ) cnt++;
        }
        ret = max(ret,cnt);
    }
    printf("%d",ret);
    return 0;
}