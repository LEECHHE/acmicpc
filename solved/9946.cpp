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
int main(){
    for( int cse = 1; ; ++cse){
        int orgin[26] = { 0 };
        int later[26] = { 0 };
        char s1[1001], s2[1001];
        scanf("%s%s", s1,s2);
        if( strcmp(s1, "END") == 0 && strcmp(s2, "END") == 0 ){
            break;
        }
        
        int len1 = (int)strlen(s1); int len2 = (int)strlen(s2);
        for( int i = 0 ; i < len1 ; ++i ){
            orgin[s1[i]-'a']++;
        }
        for( int i = 0 ; i < len2 ; ++i ){
            later[s2[i]-'a']++;
        }
        printf("Case %d: ",cse);
        if( memcmp(orgin, later, sizeof(orgin)) == 0 ) printf("same\n");
        else printf("different\n");
    }
    return 0;
}