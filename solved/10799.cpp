#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int pod = 0;
    char seq[100001]; scanf("%s", seq);
    int len = (int)strlen(seq);
    int ret = 0;
    for( int i = 0 ; i < len ; ++i ){
        if( seq[i] == '(' ){
            if( seq[i+1] == ')'){
                ret += pod;
                ++i;
//                printf("%d added on %d\n",pod,i);
            }
            else{
                ++pod;
            }
        }
        else{
            --pod;
            ++ret;
        }
    }
    printf("%d", ret);
    return 0;
}