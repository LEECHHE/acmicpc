#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int,int> intPair;
string id[3] = {"Adrian", "Bruno","Goran"};
char ans[3][101];
int main(){
    char cur = 'A';
    for( int i = 0 ; i < 101 ; ++i ){
        ans[0][i] = cur;
        cur++;
        if( cur > 'C' ) cur = 'A';
    }
    char bruno[] = { 'B','A','B','C' };
    for( int i = 0 ; i < 101 ; ++i ){
        ans[1][i] = bruno[i%4];
    }
    char goran[] = "CCAABB";
    for( int i = 0 ; i < 101 ; ++i ){
        ans[2][i] = goran[i%6];
    }
    
    int n; scanf("%d",&n);
    char sol[101]; scanf("%s",sol);
    int ret = 0;
    int idx = 0;
    vector<int> ids;
    for( int i = 0 ; i < 3 ; ++i ){
        int cnt = 0;
        for( int j = 0 ; j < n ; ++j ){
            if( sol[j] == ans[i][j] ) ++cnt;
        }
        if( cnt >= ret ){
            if( cnt == ret ){
                ids.push_back(i);
            }
            else{
                ids.clear();
                ids.push_back(i);
            }
            ret = cnt;
        }
    }
    printf("%d\n", ret);
    for( auto i : ids ){
        printf("%s\n", id[i].c_str());
    }
    return 0;
}