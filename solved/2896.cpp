#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int main(){
    int j[3], f[3];
    for( int i = 0 ; i < 3 ; ++i ) scanf("%d",&j[i]);
    for( int i = 0 ; i < 3 ; ++i ) scanf("%d",&f[i]);
    double m = (double)j[0]/f[0];
    for( int i = 1 ; i < 3 ; ++i ){
        if( (double)j[i]/f[i] < m ){
            m = (double)j[i]/f[i];
        }
    }
    for( int i = 0 ; i < 3 ; ++i ){
        printf("%lf ",(double)j[i]-m*f[i]);
    }
    return 0;
}