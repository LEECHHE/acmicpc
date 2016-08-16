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
    int n; scanf("%d", &n);
    int ret = 0;
    int maxPoint = -1;
    int score[3][4] = { 0 };
    int winner[4] = { 0 };
    
    while(n--){
        for( int i = 1; i <= 3 ; ++i ){
            int t; scanf("%d",&t);
            score[i-1][t-1]++;
            score[i-1][3] += t;
            if( i == ret ){
                maxPoint += t;
                winner[3] += t;
                winner[t-1]++;
                continue;
            }
            if( maxPoint < score[i-1][3] ){
                maxPoint = score[i-1][3];
//                printf("head is changed %d to %d\n", ret ,i);
                ret = i;
                memcpy(winner, score[ret-1], sizeof(int)*4);
            }
            else if( maxPoint == score[i-1][3] ){
                if( score[i-1][2] > winner[2] ){
//                    printf("head is changed %d to %d\n", ret ,i);
                    ret = i;
                    memcpy(winner, score[ret-1], sizeof(int)*4);
                }
                else if( score[i-1][2] < winner[2]){
                    //
                }
                else{
                    if( score[i-1][1] > winner[1] ){
//                        printf("head is changed %d to %d\n", ret ,i);
                        ret = i;
                        memcpy(winner, score[ret-1], sizeof(int)*4);
                    }
                    else if( score[i-1][1] < winner[1] ){
                        //
                    }
                    else{
                        memcpy(winner, score[ret-1], sizeof(int)*4);
                        ret = 0;
                    }
                }
            }
        }
    }
    printf("%d %d", ret, maxPoint);
    return 0;
}