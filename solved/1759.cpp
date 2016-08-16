#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
vector<char> seq;
char password[16];
int l,c;
int ja = 0;
int mo = 0;
void dfs(int step, int cur){
    if( step == l-1){
        int ja_cnt = 2;
        int mo_cnt = 1;
        for( int i = 0 ; i < l ; ++i ){
            if(ja_cnt > 0 && ( 1<<(password[i]-'a') & ja)) --ja_cnt;
            else if(mo_cnt > 0 &&(1<<(password[i]-'a') & mo)) --mo_cnt;
            
            if(ja_cnt == 0 && mo_cnt == 0) break;
        }
        if( ja_cnt == 0 && mo_cnt == 0)
            printf("%s\n", password);
        return;
    }
    for( int i = cur+1 ; i <= c-l+step+1 ; ++i ){
        password[step+1] = seq[i];
        dfs(step+1, i);
    }
}
int main(){
    ja = (1<<26)-1;
    mo = 1 + (1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
    ja ^= mo;
    scanf("%d%d",&l,&c);
    password[l] = '\0';
    seq = vector<char>(c);
    for( int i = 0 ; i < c ; ++i ){
        char temp[2]; scanf("%s", temp);
        seq[i] = temp[0];
    }
    sort(seq.begin(), seq.end());
    for( int i = 0 ; i <= c-l ; ++i ){
        password[0] = seq[i];
        dfs(0, i);
    }
    return 0;
}