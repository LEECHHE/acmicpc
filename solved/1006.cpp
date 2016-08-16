#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[10005][2];
int seq[10005][2];
int n,w;
const int INF = 50000;
int solve(int idx, int type){
    if( idx >= n ) return 0;
    int& ret = dp[idx][type];
    if( ret != -1 ) return ret;
    
    if( idx == n-1 && type == 0 ){
        if( seq[n-1][0]+seq[n-1][1] <= w ){
            return 1;
        }
        return 2;
    }
    if( idx == n-1 && type == 1 ){
        return 1;
    }
    
    ret = INF;
    if( type == 0 ){
        if( seq[idx][0] + seq[idx][1] <= w ){
            ret = min(ret, 1+solve(idx+1,0));
        }
        if( seq[idx][0]+seq[idx+1][0] <= w ){
            if( seq[idx][1]+seq[idx+1][1] <= w )
                ret = min(ret, 2+solve(idx+2,0));
            ret = min(ret, 2+solve(idx+1,1));
        }
        return ret = min(ret,1+solve(idx,1));
    }
    else{
        if( seq[idx][1]+seq[idx+1][1] <= w ){
            if( seq[idx+1][0]+seq[idx+2][0] <= w)
                ret = min(ret, 2+solve(idx+2,1));
            ret = min(ret, 2+solve(idx+2,0));
        }
        return ret = min(ret,1+solve(idx+1,0));
    }
}
int main(){
    int t; cin >> t;
    while (t--) {
        cin >> n >> w;
        memset(dp, -1, sizeof(dp));
        memset(seq,0,sizeof(seq));
        for( int i = 0 ; i < 2 ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                cin >> seq[j][i];
            }
        }
        if( n == 1 ){
            cout << (seq[0][0]+seq[0][1] <= w ? 1 : 2) << endl;
            continue;
        }
        int ret = solve(0,0);
        int s00 = seq[0][0];
        int s01 = seq[0][1];
        int sn0 = seq[n-1][0];
        int sn1 = seq[n-1][1];
        if( s00+sn0 <= w && s01+sn1 <= w ){
            seq[0][0] = seq[0][1] = seq[n-1][0] = seq[n-1][1] = INF;
            memset(dp, -1, sizeof(dp));
            ret = min(ret,solve(0,0)-2);
            seq[0][0] = s00;
            seq[0][1] = s01;
            seq[n-1][0] = sn0;
            seq[n-1][1] = sn1;
        }
        if( s00+sn0 <= w ){
            seq[0][0] = seq[n-1][0] = INF;
            memset(dp,-1,sizeof(dp));
            ret = min ( ret, solve(0,0)-1);
            seq[0][0] = s00;
            seq[n-1][0] = sn0;
        }
        if( s01+sn1 <= w ){
            seq[0][1] = seq[n-1][1] = INF;
            memset(dp,-1,sizeof(dp));
            ret = min( ret, solve(0,0)-1);
        }
        cout << ret << endl;
    }
    return 0;
}