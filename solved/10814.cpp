#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, string> client;
int main(){
    client list[100000];
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&list[i].first.first);
        list[i].first.second = i;
        cin >> list[i].second;
    }
    sort(list, list+n);
    for( int i = 0 ; i < n ; ++i ){
        printf("%d %s\n", list[i].first.first, list[i].second.c_str());
    }
    return 0;
}