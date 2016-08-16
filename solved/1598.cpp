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
void find(int& x, int& y, int target){
    x = target % 4 ? target / 4 : target / 4 - 1;
    y = target % 4 ? target % 4 : 4;
}
int main(){
    int a,b; scanf("%d%d",&a,&b);
    int x1,y1,x2,y2;
    find(x1,y1,a);
    find(x2,y2,b);
//    printf("a : %d %d, b : %d %d\n", x1,y1,x2,y2);
    printf("%d", abs(x2-x1)+abs(y2-y1));
    return 0;
}