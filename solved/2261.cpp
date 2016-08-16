#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct point{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    bool operator < (const point &v) const{
        if( y == v.y){
            return x <v.x;
        }
        else{
            return y < v.y;
        }
    }
}point;

bool cmp(const point& u, const point &v){
    return u.x < v.x;
}
int dist(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
    int n; scanf("%d",&n);
    vector<point> a(n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a.begin(), a.end(), cmp);
    set<point> cand = { a[0], a[1] };
    int ans = dist(a[0], a[1]);
    int start = 0;
    for( int i = 2 ; i < n ; ++i ){
        point now = a[i];
        while( start < i ){
            auto p = a[start];
            int x = now.x - p.x;
            if(x*x > ans){
                cand.erase(p);
                start+=1;
            }
            else{
                break;
            }
        }
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = point(-100000, now.y-d);
        auto upper_point = point(100000, now.y+d);
        auto lower = cand.lower_bound(lower_point);
        auto upper = cand.upper_bound(upper_point);
        for( auto it = lower ; it != upper ; ++it ){
            int d = dist(now, *it);
            if( d < ans ){
                ans = d;
            }
        }
        cand.insert(now);
    }
    printf("%d",ans);
    return 0;
}