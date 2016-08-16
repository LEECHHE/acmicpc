#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char s[1000001]; scanf("%s",s);
    int ret[2] = { 0 };
    int len = (int)strlen(s);
    bool isOne = s[0] == '1';
    for( int i = 1 ; i < len ; ++i ){
        if( isOne && s[i] == '0' ){
            ret[1]++;
            isOne = false;
        }
        else if( !isOne && s[i] == '1' ){
            ret[0]++;
            isOne = true;
        }
    }
    ret[isOne]++;
    printf("%d", ret[0] < ret[1] ? ret[0] : ret[1] );
    return 0;
}