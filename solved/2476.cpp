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
    int ret = 0;
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int prize = 0;
        int dice[7] = { 0 };
        int cse=0;
        int indice = 0;
        for( int j = 0 ; j < 3 ; ++j ){
            int temp; scanf("%d",&temp);
            if( dice[temp] == 1 ){
                cse = 1;
                indice = temp;
            }
            else if( dice[temp] == 2 ){
                cse = 2;
                indice = temp;
            }
            else{
                if( cse == 0 )
                    indice = max(indice,temp);
            }
            dice[temp]++;
        }
        if( cse <= 1 ){
            prize += 100*indice;
            if( cse == 1 ) prize += 1000;
        }
        else{
            prize += 10000 + indice*1000;
        }
        ret = max(prize, ret);
    }
    printf("%d", ret);
    return 0;
}