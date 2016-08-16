#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> lan;
int cnt(int r){
    int ret = 0;
    for ( auto l : lan ){
        ret += l/r;
    }
    return ret;
}
int find(int l, int r, int n){
    int count = r-l+1, step;
    int it;
    while (count>0) {
        it = l; step = count/2; it += step;
        if( !(n>cnt(it))){
            l = ++it, count -= step+1;
        }
        else{
            count = step;
        }
    }
    return l;
}
int main(){
    int k,n;scanf("%d%d",&k,&n);
    int right = 0;
    for( int i = 0 ; i < k ; ++i ){
        int t; scanf("%d",&t);
        right += t;
        lan.push_back(t);
    }
    sort(lan.begin(), lan.end());
    if( n == 1 ){
        printf("%d", lan.back());
        return 0;
    }
    printf("%d\n",find(1,lan.back(),n)-1);
    return 0;
}