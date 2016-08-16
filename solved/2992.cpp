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

int main(){
    char number[7]; scanf("%s", number);
    int len = (int)strlen(number);
    bool exist = false;
    for( int i = len - 1 ; i > 0 ; --i ){
        for ( int j = i-1 ; j >= 0 ; --j ){
            if( number[j] < number[i] ){
                swap(number[j], number[i]);
                sort(number+j+1, number+len);
                exist = true;
                break;
            }
        }
        if (exist) break;
    }
    if(!exist)
        printf("0");
    else
        printf("%s", number);
    return 0;
}