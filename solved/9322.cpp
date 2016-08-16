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

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int index[1000] = { 0 };
        string pub1[1000];
        for( int i = 0 ; i < n ; ++i ){
            cin >> pub1[i];
        }
        for( int i = 0 ; i < n ; ++i ){
            string pub2; cin >> pub2;
            for( int j = 0 ; j < n ; ++j ){
                if(pub1[j].compare(pub2) == 0){
                    index[i] = j;
                }
            }
        }
        vector<string> ans(n);
        for( int i = 0 ; i < n ; ++i ){
            string enc; cin >> enc;
            ans[index[i]] = enc;
        }
        for( auto word : ans ){
            printf("%s ", word.c_str());
        }
        printf("\n");
    }
    return 0;
}