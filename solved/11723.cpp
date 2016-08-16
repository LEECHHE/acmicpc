#include<cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int has = 0;
    int idx[21] = { 0,1 };
    for( int i = 2 ; i <= 20 ; ++i ){
        idx[i] = idx[i-1]<<1;
    }
    int all = (idx[20]<<1)-1;
    while(n--){
        char op[7]; scanf("%s", op);
        if( op[0] == 'a' && op[1] =='l' ){
            //all
            has = all;
        }
        else{
            int x; scanf("%d",&x);
            if( op[0] == 'a' ){
                    //add
                has |= idx[x];
            }
            else if(op[0] =='r'){
                //remove
                int mask = all ^ idx[x];
                has &= mask;
            }
            else if(op[0] =='c'){
                //check
                printf("%d\n", (has&idx[x]) > 0);
            }
            else if(op[0] == 't'){
                //toggle
                has ^= idx[x];
            }
            else if(op[0] == 'e'){
                //empty
                has = 0;
            }
        }
    }
    return 0;
}