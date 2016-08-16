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
pair<int, int> cover(char* s){
    int len = (int)strlen(s);
    if( len == 0 ) return make_pair(0, 0);
    if( len == 1 ) return make_pair(-1, -1);
    
    int a = -1,b = -1;
    for( a = len / 4 ; a >= 0 ; --a ){
        int remain = len - a*4;
        if( remain % 2 ) continue;
        b = remain/2;
        break;
    }
    if( b < 0 ) a = -1;
    return make_pair(a, b);
}
int main(){
    char board[505];
    scanf("%s", board);
    int before = -1;
    int len = (int)strlen(board);
    vector<pair<int, int>> ans;
    char copied[505];
    bool success = true;
    for( int i = 0 ; i < len ; ++i ){
        if( board[i] == '.'){
            strncpy(copied, board+before+1, sizeof(char)*(i-before-1));
            copied[i-before-1] = '\0';

            pair<int, int> res = cover(copied);
//            printf("%d to %d: %d, %d\n", before+1, i-1, res.first, res.second);
            ans.push_back(res);
            if( res.first < 0 ){
                success = false;
                break;
            }
            if ( !(res.first == 0 && res.second == 0) ) ans.push_back(make_pair(0, 0));
            before = i;
        }
    }
    if(success){
        if( before < len-1 ){
            strcpy(copied, board+before+1);
            ans.push_back(cover(copied));
        }
    }
    if(ans.back().first<0) printf("-1");
    else{
        for(auto b:ans){
            if( b.first == 0 && b.second == 0 ) printf(".");
            else{
                for( int i = 0 ; i < b.first*4 ; ++i ) printf("A");
                for( int i = 0 ; i < b.second*2; ++i ) printf("B");
            }
        }
    }
    return 0;
}