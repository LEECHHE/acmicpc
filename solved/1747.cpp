#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int p10[] = {1,10,100,1000,10000,100000,1000000};
bool isNotPrime[1200001] = { false };
vector<int> parlin;
bool isParlindrome(int n){
    string str = to_string(n);
    int right = (int)str.length()-1;
    int left = 0;
    bool ret = true;
    
    while(left < right){
        if( str[right] != str[left] ){
            ret = false;
            break;
        }
        ++left;
        --right;
    }
    return ret;
}
void eratos(){
    for( int i = 2 ; i <= 1200000 ; ++i ){
        if(!isNotPrime[i]){
            for( int j = i*2 ; j <= 1200000 ; j += i ){
                isNotPrime[j] = true;
            }
            if( isParlindrome(i)){
                parlin.push_back(i);
            }
        }
    }
}
int main(){
    int n; scanf("%d",&n);
    eratos();
    printf("%d", *(lower_bound(parlin.begin(), parlin.end(), n)));
    return 0;
}