#include <cstdio>
using namespace std;

int main(){
    int hour, min, sec;
    int cook;
    scanf("%d %d %d", &hour, &min, &sec);
    scanf("%d", &cook);
    
    if( (sec += cook) > 59 ){
        min += sec / 60;
        sec %= 60;
    }
    if ( min > 59 ){
        hour += min / 60;
        min %= 60;
    }
    if ( hour > 23 ){
        hour %= 24;
    }
    printf("%d %d %d", hour, min, sec);
    return 0;
}