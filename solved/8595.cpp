#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    char numbers[5000001];
    scanf("%s", numbers);
    unsigned long long result = 0;
    unsigned long long current = 0;
    for( int i = 0 ; i < n ; ++i ){
        if(numbers[i] <= '9') current = current*10 + numbers[i]-'0';
        else{
            result += current;
            current = 0;
        }
    }
    result += current;
    printf("%lld", result);
    return 0;
}