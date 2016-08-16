#include<cstdio>
using namespace std;

int main(){
    int e,f,c; scanf("%d%d%d",&e,&f,&c);
    int ret = 0;
    int emptyBottle = e+f;
    while(emptyBottle/c){
        int newBottle = emptyBottle / c;
        ret += newBottle;
        emptyBottle %= c;
        emptyBottle += newBottle;
    }
    printf("%d", ret);
    return 0;
}