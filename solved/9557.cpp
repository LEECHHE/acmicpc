#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        int d = -1;
        vector<string> ss;
        for( int i = 0 ; i < n ; ++i ){
            string s;
            cin >> s;
            ss.push_back(s);
            if(s[0] != '#'){
                d = i;
            }
        }
        if( d == -1 ){
            for( auto s : ss ){
                printf("%s ",s.c_str());
            }
        }
        else{
            for( int i = d+1 ; i < n ; ++i ){
                printf("%s ",ss[i].c_str());
            }
            printf("%s ",ss[d].c_str());
            for( int i = 0 ; i < d ; ++i ){
                printf("%s ",ss[i].c_str());
            }
        }
        printf("\n");
    }
    return 0;
}