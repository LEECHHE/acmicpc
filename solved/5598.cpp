#include<iostream>
#include<string>
using namespace std;

int main(){
	string s; cin >> s;
	for(int i = 0 ; i < s.length() ; ++i ){
		printf("%c",s[i]-3<'A'?s[i]+23:s[i]-3);
	}
	return 0;
}