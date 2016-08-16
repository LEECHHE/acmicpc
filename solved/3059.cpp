#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int c; scanf("%d",&c);
    while(c--){
        char ps[1001]; scanf("%s", ps);
        bool isIncluded[27] = { false };
        int len = (int)strlen(ps);
        int ret = 2015;
        for( int i = 0 ; i < len ; ++i ){
            int idx = ps[i]-'A';
            if( isIncluded[idx] ) continue;
            isIncluded[idx] = true;
            ret -= ps[i];
        }
        printf("%d\n",ret);
    }
    return 0;
}