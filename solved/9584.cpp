#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string pat; cin >> pat;
    int n; cin >> n;
    vector<string> ret;
    auto head = pat.begin();
    for( int i = 0 ; i < n ; ++i ){
        string str; cin >> str;
        for( auto it = str.begin(); it != str.end() ; ++it ){
            if( *head == *it || *head == '*'){
                ++head;
            }
        }
        if( head == pat.end() ){
            ret.push_back(str);
        }
        head = pat.begin();
    }
    cout << ret.size() << endl;
    for ( auto p : ret ){
        cout << p << endl;
    }
    return 0;
}