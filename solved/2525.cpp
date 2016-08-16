#include <cstdio>
using namespace std;

int main(){
    int hour, min;
    int cook;
    scanf("%d %d", &hour, &min);
    scanf("%d", &cook);
    
    if( (min += cook) > 59 ){
        hour += min / 60;
        min %= 60;
    }
    if ( hour > 23 ){
        hour %= 24;
    }
    printf("%d %d", hour, min);
    return 0;
}