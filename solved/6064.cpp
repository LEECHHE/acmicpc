#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int m,n,x,y; scanf("%d%d%d%d",&m,&n,&x,&y);
        if( m > n ){
            swap(m,n);
            swap(x,y);
        }
        int ret = x == y ? x : -1;
        y %= n;
        
        bool visited[40001] = { false };
        int elapsed = x;
        while(ret<0){
            elapsed += m;
            int cur_y = elapsed%n;
            if( visited[cur_y] ) break;
            if( cur_y == y ){
                ret = elapsed;
                break;
            }
            else{
                visited[cur_y] = true;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}