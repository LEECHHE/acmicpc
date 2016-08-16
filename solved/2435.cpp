#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int s = 0;
    int n,k; scanf("%d%d",&n,&k);
    int seq[100];
    for( int i = 0 ; i < n ; i += scanf("%d", &seq[i]));
    int head = 0;
    for ( int i = 0 ; i < k ; ++i ) s += seq[i];
    int ret = s;
    for( int i = k ; i < n ; ++i ){
        int temp = s;
        temp -= seq[head++];
        temp += seq[i];
        ret = max(ret, temp);
        s = temp;
    }
    printf("%d",ret);
    return 0;
}