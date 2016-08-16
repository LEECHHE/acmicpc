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
//1371
int main(){
    char seq[5001];
    int cnt[26] = {0};
    while( scanf("%s", seq) != -1 ){
        int len = (int)strlen(seq);
        for( int j = 0 ; j < len ; ++j ){
            if( seq[j] == ' ' || seq[j] == '\n' ) continue;
            ++cnt[seq[j]-'a'];
        }
    }

    int max = -1;
    vector<char> ret;
    for( int i = 0 ; i < 26 ; ++i ){
        if( max == cnt[i] ) ret.push_back(i+'a');
        else if( max < cnt[i] ){
            ret.clear();
            ret.push_back(i+'a');
            max = cnt[i];
        }
    }
    for ( auto c : ret ){
        printf("%c", c);
    }
    return 0;
}