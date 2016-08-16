#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> intPair;
bool visited[1000001] = { false };
int main(){
    int f,s,g,u,d; scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    if( s == g ){
        printf("0");
        return 0;
    }
    queue<pair<int,intPair>> q; //stair, buttons
    q.push(make_pair(s, make_pair(0,0)));
    visited[s] = true;
    int ret = -1;
    while (!q.empty()) {
        int floor = q.front().first;
        intPair btns = q.front().second;
        q.pop();
        if( floor + u <= f ){
            int next = floor+u;
            if( !visited[next] ){
                visited[next] = true;
                if (next == g) {
                    ret = btns.first+btns.second+1;
                    break;
                }
                q.push(make_pair(next, make_pair(btns.first+1, btns.second)));
            }
        }
        if (floor-d >= 1) {
            int next = floor-d;
            if (!visited[next]) {
                visited[next] = true;
                if (next == g) {
                    ret = btns.first+btns.second+1;
                    break;
                }
                q.push(make_pair(next, make_pair(btns.first, btns.second+1)));
            }
        }
    }
    if (ret < 0) {
        printf("use the stairs");
    }
    else{
        printf("%d",ret);
    }
    return 0;
}