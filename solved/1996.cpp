#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cmath>
using namespace std;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};
char m[1000][1001];
char ret[1000][1001] = { 0 };
int n;
bool isValid(int x, int y ){
    return 0 <= x && x < n && 0 <= y && y < n;
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", m[i]);
        ret[i][n] = '\0';
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( m[i][j] != '.' ){
                ret[i][j] = '*';
                continue;
            }
            for( int d = 0 ; d < 8 ; ++d ){
                int x = i+dx[d], y = j+dy[d];
                if(!isValid(x,y)) continue;
                if( m[x][y] == '.' ) continue;
                ret[i][j] += m[x][y]-'0';
            }
            ret[i][j] >= 10 ? ret[i][j] = 'M' : ret[i][j] += '0';
        }
    }
    for( int i = 0 ; i < n ; ++i ){
        printf("%s\n",ret[i]);
    }
    return 0;
}