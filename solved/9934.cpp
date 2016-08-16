#include <cstdio>
using namespace std;

int pow2(const int p){
    if ( p == 0 ) return 1;
    else return pow2(p-1) * 2;
}
int max;
int tree[1025] = { 0 };
void inorder(int current){
    if ( current > max || tree[current] > 0) return;
    inorder(current*2);
    scanf("%d",&tree[current]);
    inorder(current*2+1);
}
int main(){
    int k; scanf("%d", &k);
    max = pow2(k)-1;
    inorder(1);
    for( int i = 0 ; i < k ; ++i ){
        for( int j = pow2(i) ; j < pow2(i+1); ++j )
            printf("%d ",tree[j]);
        printf("\n");
    }
    return 0;
}