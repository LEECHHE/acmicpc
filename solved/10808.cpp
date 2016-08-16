#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char s[101]; scanf("%s", s);
    int fr[26] = { 0 };
    int len = (int)strlen(s);
    for( int i = 0 ; i < len ; ++i ){
        fr[s[i]-'a']++;
    }
    for(int i = 0 ; i < 26 ; ++i ){
        printf("%d ", fr[i]);
    }
    return 0;
}