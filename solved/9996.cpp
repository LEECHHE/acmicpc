#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char pattern[101];
int main(){
    int n; scanf("%d%s",&n,pattern);
    while(n--){
        char seq[101]; scanf("%s", seq);
        string ret = "DA";
        int i = 0;

        while(pattern[i] != '*') {
            if ( seq[i] != pattern[i] ) {
                ret = "NE";
                break;
            }
//            seq[i] = '-';
            ++i;
        }
        int covered = i-1;
        if( ret[0] == 'D' ){
            i = (int)strlen(pattern)-1;
            int idx = (int)strlen(seq)-1;
            while(pattern[i] != '*'){
                if( idx <= covered || seq[idx] != pattern[i] ){
                    ret = "NE";
                    break;
                }
                --i, --idx;
            }
        }
        printf("%s\n", ret.c_str());
    }
    return 0;
}