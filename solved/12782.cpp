#include <iostream>
#include <string>
using namespace std;
int abs(int a) { return a > 0 ? a : -a; }
int main(){
    int t; scanf("%d",&t);
    string s[2];
    int cnt[2] = { 0 };
    int diff = 0;
    while(t--){
        cin >> s[0] >> s[1];
        cnt[0] = cnt[1] = diff = 0;
        for( int i = 0 ; i < s[0].length() ; ++i ){
            if( s[0][i] == '1' ) ++cnt[0];
            if( s[1][i] == '1' ) ++cnt[1];
            diff += abs(s[0][i]-s[1][i]);
        }
        int ret = abs(cnt[0]-cnt[1]);
        diff -= ret;
        printf("%d\n", ret+diff/2);
    }
    return 0;
}