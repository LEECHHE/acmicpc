#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    int ret = 0;
    for( int i = 0 ; i < s.length(); ++i ){
        if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u') ++ret;
    }
    printf("%d",ret);
    return 0;
}