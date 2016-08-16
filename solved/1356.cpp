#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char number[11]; scanf("%s", number);
    int length = (int)strlen(number);
    for( int i = 0 ; i < length-1 ; ++i ){
        int right = 1,left = 1;
        for ( int k = 0 ; k <= i ; ++k )
            left *= number[k]-'0';
        for ( int j = i+1 ; j < length ; ++j )
            right *= number[j]-'0';
        if (left == right){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}