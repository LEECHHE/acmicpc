#include <cstdio>
using namespace std;

long long file_list[1000];
int main () {
    int n;
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; i++ ){
        scanf("%lld", &file_list[i]);
    }
    int size;
    scanf("%d", &size);
    long long result = 0;
    for ( int i = 0 ; i < n ; i++ ){
        if( file_list[i] % size == 0 )
            result += file_list[i] / size;
        else
            result += file_list[i] / size + 1;
    }
    printf("%lld", (long long)result * (long long)size );
    return 0;
}