#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct rect{
    double x1,y1,x2,y2;
    rect(){};
    rect(double x1, double y1, double x2, double y2):x1(x1),y1(y1),x2(x2),y2(y2){}
}rect;
double unionArea(const vector<rect>& rects){
    if(rects.empty()) return 0;
    typedef pair<double,pair<int, int>> Event;
    vector<Event> events;
    vector<double> ys;
    
    for ( int i = 0 ; i < rects.size() ; ++i ){
        ys.push_back(rects[i].y1);
        ys.push_back(rects[i].y2);
        events.push_back(Event(rects[i].x1, make_pair(1, i)));
        events.push_back(Event(rects[i].x2, make_pair(-1, i)));
    }
    
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    sort(events.begin(), events.end());
    double ret = 0;
    
    vector<int> count(ys.size()-1,0);
    for (int i = 0; i < events.size(); ++i) {
        double x = events[i].first;
        int delta = events[i].second.first;
        int rectangle = events[i].second.second;
        double y1 = rects[rectangle].y1, y2 = rects[rectangle].y2;
        for( int j = 0 ; j < ys.size() ; ++j ){
            if( y1 <= ys[j] && ys[j] < y2 ) count[j] += delta;
        }
        double cutLength = 0;
        for ( int j = 0 ; j < ys.size()-1 ; ++j ){
            if(count[j] > 0 )
                cutLength += ys[j+1]-ys[j];
        }
        if(i+1 < events.size()){
            ret += cutLength*(events[i+1].first-x);
        }
    }
    return ret;
}
int main(){
    vector<rect> rects;
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        double x1,y1,width,height; scanf("%lf%lf%lf%lf",&x1,&y1,&width,&height);
        rects.push_back(rect(x1,y1,x1+width,y1+height));
    }
    double ret = unionArea(rects);
    if( ret - int(ret) < 0.00000001 ) printf("%d", int(ret));
    else printf("%.2lf",ret);
    return 0;
}