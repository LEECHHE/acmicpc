#include <cstdio>
#include <cstring>
using namespace std;
void hanoi(int n, int a, int b){
    int t = 6-a-b;
    if( n == 1 ){
        printf("%d %d\n", a, b);
    }
    else{
        hanoi(n-1, a, t);
        printf("%d %d\n", a, b);
        hanoi(n-1, t, b);
    }
}
int main(){
    int n; scanf("%d",&n);
    char ret[102] = { 0 };
    ret[100] = '1';
    ret[101] = '\0';
    int i = 99;
    for( int k = 2 ; k <= n ; ++k ){
        int carry = 0;
        for( i = 100; ret[i] ; --i ){
            int digit = (ret[i]-'0')*2+carry;
            carry = digit/10;
            ret[i] = digit%10+'0';
        }
        ret[100] += 1;
        if( carry ) ret[i--] = '1';
    }
    printf("%s\n", ret+i+1);
    if( n <= 20 ){
        hanoi(n, 1, 3);
    }
    return 0;
}