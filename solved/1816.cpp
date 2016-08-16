#include <cstdio>
using namespace std;

int main(){
    int N; scanf("%d", &N);
    while (N--) {
        unsigned long long s; scanf("%lld",&s);
        bool NotEncrypted = false;
        for( int i = 2 ; i < 1000000 ; ++i ){
            if( s%i == 0 ){
                NotEncrypted = true;
                break;
            }
        }
        if( NotEncrypted )
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}