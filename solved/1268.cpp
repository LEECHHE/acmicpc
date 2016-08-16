#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;
int clas[1001][5];
map<int,int> ack[1001];
int main(){
    int n; scanf("%d",&n);
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 0; j < 5 ; ++j ){
            scanf("%d",&clas[i][j]);
        }
    }
    for (int j = 0; j < 5; ++j ) {
        vector<int> same[10];
        for( int i = 1 ; i <= n; ++i ){
            same[clas[i][j]].push_back(i);
        }
        for( int i=1 ; i <= 9 ; ++i ){
            for ( int j =0 ; j < same[i].size() ; ++j ){
                for( int k = j+1 ; k < same[i].size() ; ++k ){
                    ack[same[i][j]][same[i][k]]++;
                    ack[same[i][k]][same[i][j]]++;
                }
            }
        }
    }
    int ret = 1;
    int sz = ack[1].size();
    for (int i = 2 ; i <= n; ++i ) {
        if (sz < ack[i].size()) {
            sz = ack[i].size();
            ret = i;
        }
    }
    printf("%d", ret);
    return 0;
}