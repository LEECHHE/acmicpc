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

int main(){
    int t; scanf("%d",&t);
    map<int,int> accepted;
    while(t--){
        accepted.clear();
        int total; scanf("%d", &total);
        for( int i = 0 ; i < total ; ++i ){
            int a,b; scanf("%d%d",&a,&b);
            pair<int, int> rank = make_pair(total-a, total-b);
            if( accepted.empty() ){
                accepted.insert(rank);
//                printf("%d th rank is pushed at idx:%d\n", i+1, (int)accepted.size()-1);
                continue;
            }
            
            auto it = accepted.lower_bound(rank.first);
            
            if(it == accepted.end() || it->second < rank.second ){
                
                auto remove = accepted.lower_bound(rank.first);
                if( remove != accepted.begin() ) {
                    --remove;
                    while(1){
                        if( remove->second > rank.second ){
                            break;
                        }
                        if( remove == accepted.begin()){
                            accepted.erase(remove);
                            break;
                        }
                        else{
                            auto jt = remove;
                            --jt;
                            accepted.erase(remove);
                            remove = jt;
                        }
                    }
                }
                accepted.insert(rank);
//                printf("%d th rank is pushed at ..\n", i+1);
            }
        }
        printf("%d\n",(int)accepted.size());
    }
    return 0;
}