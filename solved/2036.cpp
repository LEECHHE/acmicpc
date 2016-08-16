#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    vector<long long> neg;
    vector<long long> pos;
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        long long t; scanf("%lld",&t);
        t > 0 ? pos.push_back(t) : neg.push_back(-t);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    long long ret = 0;
    while(pos.size() >= 2){
        long long a = pos.back(); pos.pop_back();
        if( pos.back() > 1 ){
            ret += a * pos.back(); pos.pop_back();
        }
        else{
            ret += a;
        }
    }
//    printf("pos :%lld\n", ret);
    while(neg.size() >= 2){
        long long a = neg.back(); neg.pop_back();
        ret += a * neg.back(); neg.pop_back();
    }
//    printf("pos :%lld\n", ret);
    while (!pos.empty()) {
        ret += pos.back();
        pos.pop_back();
    }
    while (!neg.empty()) {
        ret -= neg.back();
        neg.pop_back();
    }
    printf("%lld", ret);
    return 0;
}