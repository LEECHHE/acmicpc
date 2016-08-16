#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
int a, b;
char replace(char k){
    return (a*(k-'A')+b)%26 +'A';
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        char seq[1000001]; scanf("%d%d%s", &a,&b,seq);
        int len = (int)strlen(seq);
        for( int i = 0 ; i < len ; ++i )
        {
            printf("%c", replace(seq[i]));
        }
        printf("\n");
    }
    return 0;
}