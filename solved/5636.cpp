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
vector<int> primes;
int p10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
void erathos(){
    bool isPrime[100001] = { false };
    for( int i = 2 ; i <= 100000 ; ++i ){
        if(!isPrime[i]){
            primes.push_back(i);
            for( int j = i*2 ; j <= 100000 ; j += i ){
                isPrime[j] = true;
            }
        }
    }
}
int currentMax;
char subnum[10];
char n[256];
int toint(char* c){
    int len = (int)strlen(c);
    int ret = 0;
    for( int i = len-1 ; i >= 0 ; --i ){
        ret += p10[i]*(c[len-i-1]-'0');
    }
    return ret;
}
void setSubnum(int i, int j){
    int idx = 0;
    for( int k = i ; k <= j ; ++k ){
        subnum[idx++] = n[k];
    }
    subnum[idx] = '\0';
}
int main(){
    erathos();
    while(1){
        scanf("%s",n);
        if(n[0] == '0' && n[1] == '\0') break;
        int len = (int)strlen(n);
        currentMax = 0;
        for( int i = 0 ; i < len ; ++i ){
            if( n[i] == '2' && currentMax == 0 ){
                currentMax = 2;
            }
            for( int j = i ; j < len && j < i+6 ; ++j ){
                setSubnum(i, j);
                int target = toint(subnum);
                if( target % 2 == 0 ) continue;
                if( target < currentMax ) continue;
                if( *lower_bound(primes.begin(), primes.end(), target) == target ){
                    currentMax = target;
                }
            }
        }
        printf("%d\n", currentMax);
    }
    return 0;
}