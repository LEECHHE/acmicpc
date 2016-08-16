#include <iostream>
#include <string>
using namespace std;

int main(){
	string ss; cin >> ss;
	string word; cin >> word;
	int ret = 0;
	for( int i = 0 ; i < ss.length(); ++i ){
		if( i-1+word.length() >= ss.length()) break;
		bool success = true;
		for( int j = 0 ; j < word.length() ; ++j ){
			if( ss[i+j] != word[j] ) {
				success = false;
				break;
			}
		}
		if( success ) ++ret;
	}
	printf("%d",ret);
	return 0;
}