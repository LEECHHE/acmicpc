#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    bool ret = true;
    for( int i = 0 ; i < s.length()/2; ++i ){
        if( s[i] != s[s.length()-i-1] ){
            ret = false;
            break;
        }
    }
    printf("%d",ret);
    return 0;
}