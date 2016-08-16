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
typedef pair<int, int> intPair;

bool isPalindrome(char* w1, char* w2){
    int left_len = (int)strlen(w1);
    int left = 0; int right = (int)(strlen(w2))+left_len-1;
    bool ret = true;
    while(left<right){
        int left_idx = left;
        int right_idx = right;
        char* leftWord = w1;
        char* rightWord = w1;
        if( left>= left_len){
            leftWord = w2;
            left_idx -= left_len;
        }
        if( right >= left_len ){
            right_idx -= left_len;
            rightWord = w2;
        }
        if( leftWord[left_idx] != rightWord[right_idx] ){
            ret = false;
            break;
        }
        left++;
        right--;
    }
    
    return ret;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int k; scanf("%d",&k);
        char word[100][10001];
        for( int i = 0 ; i < k ; ++i ){
            scanf("%s", word[i]);
        }
        char ret[20005] = { '\0' };
        for( int i = 0 ; i < k-1 ; ++i ){
            for ( int j = i+1 ; j < k ; ++j ){
                if( isPalindrome(word[i], word[j]) ){
                    strcpy(ret, word[i]);
                    strcpy(ret+strlen(word[i]), word[j]);
                    break;
                }
                if( isPalindrome(word[j], word[i]) ){
                    strcpy(ret, word[j]);
                    strcpy(ret+strlen(word[j]), word[i]);
                    break;
                }
            }
            if( ret[0] != '\0' )
                break;
        }
        
        if( ret[0] =='\0' ) printf("0\n");
        else printf("%s\n", ret);
    }
    return 0;
}