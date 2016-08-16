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
pair<int, int> node[26];
void maketree( int idx, char par, char* child){
    if( idx == -1 ) return;
    if ( idx == par-'A' ){
        int ch1 = child[0] == '.'? -1 : child[0]-'A';
        int ch2 = child[1] == '.'? -1 : child[1]-'A';
        node[par-'A'].first = ch1; node[par-'A'].second = ch2;
        return;
    }
    maketree(node[idx].first, par, child);
    maketree(node[idx].second, par, child);
}
void preorder(int idx){
    if( idx == -1 ) return;
    printf("%c", idx+'A');
    preorder(node[idx].first);
    preorder(node[idx].second);
}

void inorder(int idx){
    if( idx == -1 ) return;

    inorder(node[idx].first);
    printf("%c", idx+'A');
    inorder(node[idx].second);
}

void postorder(int idx){
    if( idx == -1 ) return;

    postorder(node[idx].first);
    postorder(node[idx].second);
    printf("%c", idx+'A');
}
int main(){
    int n; scanf("%d", &n);
    for( int i = 0 ; i < 26 ; ++i ) node[i] = make_pair(-1, -1);
    for( int i = 0 ; i < n ; ++i ){
        char par; char child[2];
        cin >> par >> child[0] >> child[1];
        maketree(0, par, child);
    }
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;
}