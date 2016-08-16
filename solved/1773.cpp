#include <cstdio>
using namespace std;
bool boom[2000001] = { false };
int main(){
    int n,c; scanf("%d%d",&n,&c);
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int k; scanf("%d",&k);
        for( int t = k ; t <= c ; t += k ){
            if(!boom[t]){
                boom[t] = true;
                ++ret;
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}