#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> intPair;
int seq[100000];
int solve(int left, int right){
    if( left == right ) return seq[left];
    int mid = (left+right)/2;
    int ret = max(solve(left, mid), solve(mid+1, right));
    int leftIdx = mid;
    int rightIdx = mid+1;
    int h = min(seq[leftIdx], seq[rightIdx]);
    ret = max(h*2, ret);
    while (leftIdx > left || rightIdx < right) {
        if (leftIdx > left && (right == rightIdx || seq[leftIdx-1] > seq[rightIdx+1])){
            --leftIdx;
            h = min(h, seq[leftIdx]);
        }
        else{
            ++rightIdx;
            h = min(h, seq[rightIdx]);
        }
        ret = max(ret, h*(rightIdx-leftIdx+1));
    }
    return ret;
}
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    printf("%d", solve(0, n-1));
    return 0;
}