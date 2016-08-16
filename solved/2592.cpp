#include <cstdio>
using namespace std;

int main(){
    int num[100] = { 0 };
    int sum = 0;
    int maxCount = 0;
    int maxIndex = -1;
    for ( int i = 0 ; i < 10 ; ++i ){
        int temp; scanf("%d", &temp);
        if( ++num[temp/10-1] > maxCount ){
            maxCount = num[temp/10-1];
            maxIndex = temp/10;
        }
        sum += temp;
    }
    printf("%d\n%d", sum/10, maxIndex * 10);
    return 0;
}