#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s[10];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    string ret ="Eyfa";
    for( int i = 0 ; i < n ; ++i ){
        cin >> s[i];
    }
    for( int i = 0; i < n ; ++i ){
        string ss; cin >> ss;
        if( ret[0] == 'N') continue;
        for( int j = 0 ; j < m ; ++j ){
            if(!(ss[j*2] == s[i][j] && ss[j*2+1] == s[i][j] )){
                ret = "Not Eyfa";
                break;
            }
        }
    }
    cout << ret;
    return 0;
}