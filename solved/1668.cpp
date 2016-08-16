#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> seq;
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        seq.push_back(t);
    }
    int cnt = 1;
    int m = seq[0];
    for( int i = 1 ; i < n ; ++i ){
        if( seq[i] > m ){
            cnt++;
            m = seq[i];
        }
    }
    printf("%d\n",cnt);
    cnt = 1;
    m = seq[n-1];
    for( int i = n-1 ; i >= 0 ; --i ){
        if( seq[i] > m ){
            cnt++;
            m = seq[i];
        }
    }
    printf("%d\n",cnt);
    return 0;
}