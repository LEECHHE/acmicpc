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
int p2[] = { 1,2,4,8,16,32};
int code[] = { 0, 15, 19, 28, 38, 41, 53, 58 };
int toint(char* c, int idx){
    int start = (idx-1)*6;
    int ret = 0;
    for( int i = 5 ; i >=0 ; --i ){
        if(c[start+i] == '1')
            ret += p2[5-i];
    }
    return ret;
}
int main(){
    int n ; scanf("%d", &n);
    char pwd[55];
    string ret = "";
    scanf("%s", pwd);
    for( int i = 1 ; i <= n ; ++i ){
        int cur = toint(pwd, i);
//        printf("current : %d\n", cur);
        string word = "";
        for( int j = 0 ; j < 8 ; ++j ){
            int result = cur^code[j];
            if( result == 0 ){
                word = 'A'+j;
                break;
            }
            else{
                int idx = (int)(find(p2, p2+6, result)-p2);
                if( idx < 6 ){
                    word = 'A'+ j;
                    break;
                }
            }
        }
        if( word.length() == 0 ){
            ret = to_string(i);
            break;
        }
        ret += word;
    }
    printf("%s",ret.c_str());
    return 0;
}