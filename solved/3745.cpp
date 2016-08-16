#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    while(1){
        int t;
        if( scanf("%d",&t) < 0 ) break;
        int seq[1000000];
        for( int i = 0 ; i < t ; i += scanf("%d",&seq[i]));
        
        vector<int> lis;
        for( int i = 0 ; i < t ; ++i ){
            if( lis.empty() ){
                lis.push_back(seq[i]);
                continue;
            }
            if( seq[i] > lis.back() ){
                lis.push_back(seq[i]);
            }
            else{
                int idx = lower_bound(lis.begin(), lis.end(), seq[i])-lis.begin();
                lis[idx] = seq[i];
            }
        }
        printf("%d\n",(int)lis.size());
    }
    return 0;
}