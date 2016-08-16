#include <cstdio>
using namespace std;
int main(){
    int next[1001];
    for( int i = 0 ; i <= 1000 ; ++i ) next[i] = -1;
    int n,p; scanf("%d%d", &n,&p);
    int current = n;
    while(next[current] < 0){
        next[current] = (current*n)%p;
        current = next[current];
//        printf("to %d\n", current);
    }
    int cnt = 1;
    int target = current;
    while(target != next[current]){
        current = next[current];
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}