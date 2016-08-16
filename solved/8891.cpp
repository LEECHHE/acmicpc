#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> intPair;
int first(int k){
    return (k-1)*k/2+1;
}
int find(int k){
    if( k == 1) return 1;
    
    for( int i = 1 ; ; ++i ){
        if( first(i) > k ){
            return i-1;
        }
    }
}
intPair pos(int target){
    int terms = find(target);
    int fir = first(terms);
    int dist = target-fir;
    return intPair(1+dist, terms-dist);
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int a,b; scanf("%d%d",&a,&b);
        intPair p1 = pos(a), p2 = pos(b);
        intPair dest = intPair(p1.first+p2.first,p1.second+p2.second);
        int t = dest.first+dest.second;
        int s = first(t-1);
        printf("%d\n", s+dest.first-1);
    }
    return 0;
}