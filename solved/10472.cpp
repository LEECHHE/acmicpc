#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> intPair;
int mask[] = { 0b000001011, 0b000010111, 0b000100110,
    0b001011001, 0b010111010, 0b100110100,
    0b011001000, 0b111010000, 0b110100000 };
int click(int current, int x, int y){
    return current^mask[3*x+y];
}
int abs(int k){
    return k < 0 ? -k : k;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int target = 0;
        for( int i = 0 ; i < 3 ; ++i ){
            char grid[4]; scanf("%s", grid);
            for( int j = 0 ; j < 3 ; ++j ){
                if( grid[j] == '*' ) target |= 1<<(i*3+j);
            }
        }
        if( target == 0 ){
            printf("0\n");
            continue;
        }
        queue<intPair> q;
        q.push(intPair(0,1));
        q.push(intPair(target,-1));
        int visited[1<<9] = { 0 };
        visited[0] = 1;
        visited[target] = -1;
        int ret = -1;
        while(!q.empty()){
            int state = q.front().first;
            int dir = q.front().second;
            q.pop();
            for( int x = 0 ; x < 3 ; ++x ){
                for( int y = 0 ; y < 3 ; ++y ){
                    int next = click(state,x,y);
                    if( visited[next] == 0 ){
                        visited[next] = dir+(dir>0?1:-1);
                        q.push(intPair(next,visited[next]));
                    }
                    else if( visited[next] * dir < 0 ){
                        ret = abs(dir)+abs(visited[next]);
                        break;
                    }
                }
                if( ret >= 0 ) break;
            }
            if( ret >= 0 ) break;
        }
        printf("%d\n",ret-1);
    }
    return 0;
}