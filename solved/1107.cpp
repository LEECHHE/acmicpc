#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int ret;
int l;
void search(vector<int>& p, int cur, int len){
    if( len == l ){
        ret = min(ret, abs(n-cur)+len);
        return;
    }
    for( auto num : p ){
        search(p,cur*10+num,len+1);
    }
}
int main(){
    scanf("%d",&n);
    string s = to_string(n);
    int m; scanf("%d",&m);
    bool broken[10] = { false };
    for( int i =0 ; i < m ; ++i ){
        int a; scanf("%d",&a);
        broken[a] = true;
    }
    int manual = abs(n-100);
    bool safe = true;
    int cur = 0;
    for( int i = 0 ; i < s.length() ; ++i ){
        if(broken[s[i]-'0']){
            safe = false;
            break;
        }
        cur = (cur+(s[i]-'0'))*10;
    }
    if( safe )
        printf("%d", min(manual, (int)s.length()));
    else{
        vector<int> possible;
        for( int i = 0 ; i < 10 ; ++i ){
            if( !broken[i] ) possible.push_back(i);
        }
        ret = 1000000;
        int limit = s.length() == 6 ? 6 : s.length()+1;
        for( l = 1 ; l <= limit ; ++l )
            search(possible, 0, 0);
        printf("%d",min(ret,manual));
    }
    return 0;
}