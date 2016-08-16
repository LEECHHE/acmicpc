#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    char a[11], b[11];
    while(1){
        scanf("%s%s",a,b);
        if( a[0] == '0' && b[0] == '0' ) break;
        if( strlen(a) < strlen(b)) swap(a,b);
        int lenA = (int)strlen(a)-1, lenB = (int)strlen(b)-1;
        int ret = 0;
        bool carry = 0;
        while (lenA >=0 && lenB >= 0) {
            carry =  (a[lenA]-'0' + b[lenB]-'0'+carry) > 9;
            ret += carry;
            lenA--; lenB--;
        }
        while( carry && lenA >= 0){
            carry = a[lenA--] == '9';
            ++ret;
        }
        printf("%d\n",ret);
    }
    return 0;
}