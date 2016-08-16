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
typedef pair<int, int> intPair;
int main(){
    string data[6][4] = {
        { "SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE" },
        {"N2 Bomber","Heavy Fighter","Limited","21"},
        {"J-Type 327","Light Combat","Unlimited","1"},
        {"NX Cruiser", "Medium Fighter", "Limited","18"},
        {"N1 Starfighter", "Medium Fighter", "Unlimited","25"},
        {"Royal Cruiser","Light Combat","Limited","4"}};
    
    for( auto d : data ){
        printf("%-15s%-15s%-11s%-10s\n",d[0].c_str(),d[1].c_str(),d[2].c_str(),d[3].c_str());
    }
    return 0;
}