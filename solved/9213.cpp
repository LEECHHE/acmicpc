#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX  1000000
int base[MAX] = { 0 };
void getBase(){
    for ( int i = 1 ; i <= MAX ; ++i ){
        base[i] = i;
    }
    for( int i = 2 ; i <= MAX ; ++i ){
        for( long long j = (long long)i*i ; j <= MAX ; j += i ){
            if( base[j] == j ) base[j] = i;
        }
    }
}
bool isPrime(int n){
    if( n <= 1 ) return false;
    return base[n] == n;
}
long long dsum[MAX] = { 0 };
typedef pair<int,int> intPair;
vector<intPair> factoring(int n){
    vector<intPair> ret;
    while(n>1){
        int factor = base[n];
        int cnt = 0;
        while( base[n] == factor ){
            ++cnt;
            n /= factor;
        }
        ret.push_back(intPair(factor,cnt));
    }
    return ret;
}
//long long pow(int a, int b){
//    if ( b == 0 ) return 1;
//    if( b == 1) return a;
//    if( b % 2 ) return b*pow(a,b-1);
//    else{
//        long long ret = pow(a,b/2);
//        return ret*ret;
//    }
//}
long long get_divisors_sum(int n){
  if( isPrime(n) ) return 1+n;
  vector<intPair> factors = factoring(n);
  if( factors.size() == 1 ){
      return dsum[n/factors[0].first]*factors[0].first+1;
  }
  else{
      long long ret = 1;
      for( auto factor : factors ){
          ret *= dsum[(int)pow(factor.first, factor.second)];
      }
      return ret;
  }
}
void preprocess(){
  getBase();
  //TODO : get the sum of each number. fill in dsum.
  for( int n = 2 ; n <= MAX ; ++n ){
      dsum[n] = get_divisors_sum(n);
  }
}
int abs(int n){ return n < 0 ? -n : n; }
int get_badness(int n){
  //n-(dsum[i]-i)
  return abs(2*n-dsum[n]);
}
int main(){
    preprocess();

    for( int t = 1 ; ; ++t){
        int start, stop, badness; cin >> start >> stop >> badness;
        if( start == 0 && stop == 0 && badness == 0 ) break;
        int cnt = 0;
        for( int n = start ; n <= stop ; ++n ){
            if( get_badness(n) <= badness ) ++cnt;
        }
        cout << "Test "<<t<<": "<<cnt << endl;
    }
    return 0;
}