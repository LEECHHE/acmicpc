#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int idx[26] = { 1 };
int n,k;
int covered[50] = { 0 };
bool visited[1<<26] = { false };
int ret = 0;
void dfs(int step, int state){
    if( step == 0 ){
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            bool success = true;
            for ( int bit = 0 ; bit < 26 ; ++bit ){
                if( covered[i] & idx[bit] ){
                    if (!(state & idx[bit])) {
                        success = false;
                        break;
                    }
                }
            }
            if( success ) ++cnt;
        }
        ret = max(ret, cnt);
        return;
    }
    for( int i = 0 ; i < 26 ; ++i ){
        if( (state & idx[i]) == 0 ){
            int nextState = state | idx[i];
            if (visited[nextState]) continue;
            visited[nextState] = true;
            dfs(step-1, nextState);
        }
    }
}

int main(){
    for( int i = 1 ; i < 26 ; ++i ){
        idx[i] = idx[i-1]<<1;
    }
    scanf("%d%d",&n,&k);
    int init = idx[0] | idx[13] | idx[19] | idx[8] | idx[2];
    for( int i = 0 ; i < n ; ++i ){
        int state = init;
        char str[16]; scanf("%s", str);
        int len = (int)strlen(str);
        for( int j = 4 ; j <= len-5 ; ++j ){
            state |= idx[str[j]-'a'];
        }
        covered[i] = state;
    }
    
    if( k < 5 ){
        printf("0");
        return 0;
    }
    visited[init] = true;
    dfs(k-5, init);
    printf("%d",ret);
    return 0;
}