#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char number[33];
    int x;
    unsigned long power = 1;
    scanf("%s %d", number, &x);
    unsigned long result = 0;
    for ( int i = strlen(number) - 1; i >= 0 ; --i, power *= x){
        unsigned long n = number[i];
        if(n >= 'A') n = n - 'A' + 10;
        else n -= '0';
        
        result += n * power;
    }
    printf("%lu", result);
    return 0;
}