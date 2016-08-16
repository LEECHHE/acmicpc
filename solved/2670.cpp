#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int N; scanf("%d", &N);
    double cur; scanf("%lf", &cur);
    double ret = 0;
    if( N == 1 ){
        printf("%.3lf", cur);
        return 0;
    }
    for( int i = 1 ; i < N ; ++i ){
        double t;
        scanf("%lf",&t);
        ret = fmax(cur, ret);
        if( cur < 1 ){
//            printf("cmp %lf with %lf\n", cur,ret);
            cur = 1;
        }

        cur *= t;
    }
    ret = fmax(cur, ret);
    printf("%.3lf", ret);
    return 0;
}