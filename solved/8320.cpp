#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        int cur = i;
        int g = 1;
        for( int k = 2 ; cur > 1 && k <= i ; ++k ){
            int cnt = 0;
            while(cur > 1 && cur%k == 0){
                cur /= k;
                ++cnt;
            }
            if( cnt > 0 )
                g *= cnt+1;
        }
//        printf("g : %d\n", g);
//        printf("%d for cnt : %d\n",i,(int)ceil((double)g/2));
        ret += ceil((double)g/2);
    }
    printf("%d",ret);
    return 0;
}