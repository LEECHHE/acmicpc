#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std;
typedef pair<double, double> doublePair;
typedef struct line{
    double a,b,c;
    line(){}
    line(double a,double b,double c):a(a),b(b),c(c){}
}line;
const int INF = 5000;
doublePair cross(line l1, line l2){
    double c = l1.a*l2.b-l1.b*l2.a;
    if( abs(c) < 0.0000001 ) return doublePair(INF, INF);
    return doublePair((l1.b*l2.c-l1.c*l2.b)/c, (l1.c*l2.a-l1.a*l2.c)/c);
}
double dist(doublePair& a, doublePair& b){
    double ret = sqrt(pow(a.first-b.first, 2)+pow(a.second-b.second,2));
    return ret < 0.000000001 ? 0 : ret;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        line l[3];
        for( int i = 0 ; i < 3 ; ++i ){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            l[i] = line(a,b,c);
        }
        doublePair p[3];
        bool isParallel = false;
        for ( int i = 0 ; i < 3 ; ++i ){
            p[i] = cross(l[i], l[(i+1)%3]);
            if( p[i].first == INF ){
                isParallel = true;
                break;
            }
        }
        if( isParallel ){
            printf("0.0000\n");
            continue;
        }
        double len[3];
        for( int i = 0 ; i < 3 ; ++i ){
            len[i] = dist(p[i], p[(i+1)%3]);
        }
        double s = (len[0]+len[1]+len[2])/2;
        printf("%.4lf\n",sqrt(s*(s-len[0])*(s-len[1])*(s-len[2])));
    }
    return 0;
}