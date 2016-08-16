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
long long songList[100] = { 0 };
void share(vector<int>& participants){
    int len = (int)participants.size();
    for ( int i = 0 ; i < len ; ++i ){
        for( int j = 0 ; j < len ; ++j ){
            songList[participants[j]] |= songList[participants[i]];
        }
    }
}
void makeSong(vector<int>& participants, int number){
    for( auto p : participants ){
        songList[p] |= 1 << number;
    }
}
void printResult(int n){
    long long songs = songList[0];
    printf("1\n");
    for( int i = 1 ; i < n ; ++i){
        if( songList[i] == songs )
            printf("%d\n", i+1);
    }
}
int main(){
    int n,e; scanf("%d%d", &n, &e);
    int song_count = -1;
    while(e--){
        int attend_number; scanf("%d",&attend_number);
        vector<int> participants;
        bool sunyeong = false;
        for( int i = 0 ; i < attend_number ; ++i ){
            int temp; scanf("%d", &temp);
            if( temp == 1 ){
                sunyeong = true;
                song_count++;
            }
            participants.push_back(temp-1);
        }
        sunyeong ? makeSong(participants, song_count) : share(participants);
    }
    printResult(n);
    return 0;
}