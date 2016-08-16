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
bool moveable(pair<int,int> from, pair<int, int> to ){
    return (abs(from.first-to.first) * abs(from.second-to.second)) == 2;
}
int main(){
    bool visited[6][6] = { false };
    char pos[3]; scanf("%s", pos);
    int cnt = 0;
    pair<int, int > start = make_pair(pos[0]-'A', pos[1]-'1');
    pair<int,int> before = start;
    pair<int,int> next;
    bool success = true;
    for( int i = 1 ; i < 36 ; ++i ){
        scanf("%s", pos);
        if(success){
            next = make_pair(pos[0]-'A', pos[1]-'1');
            if(!visited[next.first][next.second] && moveable(before, next) ){
                visited[next.first][next.second] = true;
                cnt++;
            }
            else{
                success = false;
            }
            before = next;
        }
    }
    
    if(success){
        if( moveable(next, start) ){
            cnt++;
        }
        else{
            success = false;
        }
    }
    if( cnt < 36 ) success = false;
    if( success ) printf("Valid");
    else printf("Invalid");
    return 0;
}