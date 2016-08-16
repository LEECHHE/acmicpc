#include <cstdio>
#include <cstring>
using namespace std;
char num[1000001];
int cur = 0;

int main(){
    scanf("%s", num);
    int len = (int)strlen(num);
    if( len < 2 ){
        printf("0\n");
        (num[0]-'0')%3 == 0 ? printf("YES") : printf("NO");
        return 0;
    }
    for( int i = 0 ; i < len ; ++i ){
        cur += num[i];
    }
    cur -= '0'*len;
    int ret = 1;
    while (cur >= 10) {
        int t = 0;
        while (cur) {
            t += cur%10;
            cur /= 10;
        }
        cur = t;
        ++ret;
    }
    printf("%d\n",ret);
    cur % 3 == 0 ? printf("YES") : printf("NO");
    return 0;
}