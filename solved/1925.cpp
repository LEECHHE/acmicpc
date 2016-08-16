#include <cstdio>
#include <utility>
using namespace std;
int x[3],y[3];
int p2(int i){
    return i*i;
}
int dotProduct( int i ){
    pair<int, int> v1 = make_pair(x[(i+1)%3]-x[i],y[(i+1)%3]-y[i]);
    pair<int, int> v2 = make_pair(x[(i+2)%3]-x[i],y[(i+2)%3]-y[i]);
    return v1.first*v2.first+v1.second*v2.second;
}
int main(){

    for( int i = 0 ; i < 3 ; ++i ){
        scanf("%d%d",&x[i],&y[i]);
    }
    bool case1 = false;
    for( int i = 0 ; i < 3 ; ++i ){
        if( x[i] == x[(i+1)%3] && y[i] == y[(i+1)%3] ){
            case1 = true;
            break;
        }
    }
    if(!case1 && ((y[1]-y[0])*(x[2]-x[0]) == (x[1]-x[0])*(y[2]-y[0]))){
        case1 = true;
    }
    if(case1){
        printf("X");
        return 0;
    }
    int len[3] = { p2(x[1]-x[0])+p2(y[1]-y[0]),p2(x[2]-x[1])+p2(y[2]-y[1]),p2(x[2]-x[0])+p2(y[2]-y[0])};
    if( len[0] == len[1] && len[1] == len[2] ){
        printf("JungTriangle");
        return 0;
    }
    bool isTwo = len[0] == len[1] || len[1] == len[2] || len[0] == len[2];
    int angle = 1;
    for( int i = 0 ; i < 3 ; ++i ){
        int k = dotProduct(i);
        if( k == 0 ){
            angle = 0;
            break;
        }
        else if( k < 0 ){
            angle = -1;
            break;
        }
    }
    if( angle > 0 ){
        printf("Yeahkak");
    }
    else if( angle == 0 ){
        printf("Jikkak");
    }
    else{
        printf("Dunkak");
    }
    if(isTwo) printf("2");
    printf("Triangle");
    return 0;
}