#include<cstdio>
using namespace std;
double ret = 0.0;
int n;
double pos[4];
bool visited[35][35] = { false };
void dfs(int x, int y, int step, double cur){
    if( step == n ){
        ret += cur;
        return;
    }
    visited[x][y] = true;
    if( !visited[x+1][y] ){
        dfs(x+1, y, step+1,cur*pos[0]);
    }
    if( !visited[x-1][y]){
        dfs(x-1, y, step+1, cur*pos[1]);
    }
    if( !visited[x][y-1] ){
        dfs(x,y-1,step+1,cur*pos[2]);
    }
    if( !visited[x][y+1] ){
        dfs(x,y+1,step+1,cur*pos[3]);
    }
    visited[x][y] = false;
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < 4 ; ++i ){
        int temp; scanf("%d", &temp);
        pos[i] =(double)temp/100;
    }
    dfs(18,18,0,1);
    printf("%.10lf",ret);
}