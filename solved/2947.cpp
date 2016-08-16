#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void print(int *seq){
    for( int i = 0 ; i < 5 ; ++i ){
        printf("%d ",seq[i]);
    }
    printf("\n");
}
int main(){
    int seq[5];
    int ans[5] = { 1, 2, 3, 4, 5 };
    for( int i = 0 ; i < 5 ; i += scanf("%d",&seq[i]));
    while(memcmp(seq, ans, sizeof(ans))){
        for( int i = 1 ; i < 5 ; ++i ){
            if( seq[i] < seq[i-1] ){
                int t = seq[i];
                seq[i] = seq[i-1];
                seq[i-1] = t;
                print(seq);
            }
        }
    }
    return 0;
}