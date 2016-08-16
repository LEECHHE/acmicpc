#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int cnt[26] = { 0 };
    vector<char> ans;
//    int _max = 4;
//    char name[150][31];
    for( int i = 0 ; i < n ; ++i ){
        char name[31]; scanf("%s", name);
        cnt[name[0]-'a']++;
    }
    
    for( int i = 0 ; i < 26 ; ++i ){
        if( cnt[i] < 5 ) continue;
        ans.push_back(i+'a');
    }
    if( ans.empty() ) printf("PREDAJA\n");
    else{
        for( auto ch : ans ){
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}