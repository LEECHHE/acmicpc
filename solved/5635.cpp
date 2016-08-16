#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
typedef struct person{
    string name;
    int bday[3];
} person;
bool cmp(const person& a, const person& b){
    if(a.bday[2] == b.bday[2]){
        if(a.bday[1] == b.bday[1]){
            return a.bday[0] < b.bday[0];
        }
        else
            return a.bday[1] < b.bday[1];
    }
    else{
        return a.bday[2] < b.bday[2];
    }
}
int main(){
    vector<person> p;
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        person k;
        cin >> k.name >> k.bday[0] >> k.bday[1] >> k.bday[2];
        p.push_back(k);
    }
    sort(p.begin(), p.end(), cmp);
    printf("%s\n%s",p.back().name.c_str(),p[0].name.c_str());
    return 0;
}