#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map< vector<int> , int > arr;
void precalc(int n, int k){
    vector<int> perm;
    for( int i = 1 ; i <= n ; ++i ) perm.push_back(i);
    
    queue<pair<vector<int>, int>> q;
    q.push(make_pair(perm, 0));
    arr[perm] = 0;
    while(!q.empty()){
        vector<int> cur = q.front().first;
        int step = q.front().second;
        q.pop();
        for( int i = 0 ; i <= n-k ; ++i ){
            reverse(cur.begin()+i, cur.begin()+i+k);
            if(arr[cur] == 0){
                arr[cur] = step+1;
                q.push(make_pair(cur, step+1));
            }
            reverse(cur.begin()+i, cur.begin()+i+k);
        }
    }
}

int main(){
    int n,k; scanf("%d%d",&n,&k);
    vector<int> seq(n);
    bool isSorted = true;
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d", &seq[i]);
        if( isSorted && i > 0){
            isSorted = seq[i] > seq[i-1];
        }
    }
    precalc(n,k);
    int ret;
    if( isSorted ) ret = 0;
    else ret = arr[seq] == 0 ? -1 : arr[seq];
    printf("%d", ret);
    return 0;
}