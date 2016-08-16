#include <cstdio>
using namespace std;
#define TIME_LIMIT 210
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    int current = 0;
    while(n--){
        int temp; char answer; scanf("%d",&temp); getchar();
        scanf("%c",&answer);
        current += temp;
        if( current >= TIME_LIMIT ){
            printf("%d", k);
            break;
        }
        if( answer == 'T' )
            if( ++k > 8 ) k %= 8;
    }
    return 0;
}