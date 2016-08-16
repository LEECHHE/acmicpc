#include <cstdio>
using namespace std;
char number[11];
bool increasing[10];
int n;
bool dfs(int before, int selected, int step){
    if( step == n ){
        number[n+1] = '\0';
        return true;
    }
    if( increasing[step] ){
        for( int i = before+1 ; i <= 9 ; ++i ){
            if( (selected & 1 <<i )== 0){
                if( dfs(i, selected | 1<<i , step+1) ){
                    number[step+1] = '0'+i;
                    return true;
                }
            }
        }
    }
    else{
        for( int i = before-1; i >= 0 ; --i ){
            if( (selected & 1 << i) == 0 ){
                if( dfs(i, selected | 1 <<i, step+1)){
                    number[step+1] = '0'+i;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d",&n);

    for( int i = 0 ; i < n ; ++i ){
        char eq[2]; scanf("%s", eq);
        increasing[i] = eq[0] == '<';
    }
    for( int selected = 9 ; selected >=0 ; --selected ){
        if(dfs(selected, 1<<selected,0)){
            number[0] = selected+'0';
            printf("%s\n", number);
            break;
        }
    }
    for( int selected = 0 ; selected <= 9 ; ++selected ){
        if( dfs(selected, 1<<selected, 0)){
            number[0] = selected+'0';
            printf("%s\n", number);
            break;
        }
    }
    return 0;
}