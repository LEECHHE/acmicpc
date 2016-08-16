#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    queue<int> books;
    queue<int> boxes;
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        boxes.push(t);
    }
    for( int i =0  ; i < m ; ++i ){
        int t; scanf("%d",&t);
        books.push(t);
    }
    long long ret = 0;
    while (1) {
        int box = boxes.front();
        while (!books.empty() && box >= books.front()) {
            box -= books.front();
            books.pop();
        }
        ret += box;
        boxes.pop();
        if( books.empty() ){
            while (!boxes.empty()) {
                ret += boxes.front();
                boxes.pop();
            }
            break;
        }
    }
    printf("%lld",ret);
    return 0;
}