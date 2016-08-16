#include<cstdio>
using namespace std;
int main(){
    int n,w,h; scanf("%d%d%d",&n,&w,&h);
    int maxLength = w*w+h*h;
    for( int i = 0 ; i < n ; ++i ){
        int temp; scanf("%d",&temp);
        if( maxLength < temp * temp ) printf("NE\n");
        else printf("DA\n");
    }
    return 0;
}