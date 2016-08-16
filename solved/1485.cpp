#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> intPair;
typedef long long ll;
intPair pos[4];
ll dist(intPair p1, intPair p2){
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        for( int i = 0; i < 4 ; ++i ){
            scanf("%d%d",&pos[i].first,&pos[i].second);
        }
        sort(pos,pos+4);
        ll d[4] = { dist(pos[0], pos[1]), dist(pos[0],pos[2]), dist(pos[1], pos[3]), dist(pos[2],pos[3]) };
        bool ret = true;
        for( int i = 0 ; i < 3 ; ++i ){
            if( d[i] != d[i+1] ){
                ret = false;
                break;
            }
        }
        if( ret ) ret = dist(pos[0], pos[3]) == dist(pos[1], pos[2]);
        printf("%d\n",ret);
    }
    return 0;
}