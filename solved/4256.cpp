#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> range;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void print(range p, range i, int l){
	printf("preorder : (%d,%d), inorder : (%d,%d), pos: %d\n", p.first, p.second,i.first,i.second,l);
	getchar();
}
void toPostOrder(range _pre, range _in, int pos){
	if( _pre.first == _pre.second) return;
//	print(_pre,_in,pos);
	int root_value = preorder[_pre.first];

	printf("val: %d\n",root_value);
	int left_length = find(inorder.begin()+_in.first,
			inorder.begin()+_in.second, root_value)-(inorder.begin()+_in.first); 
	int right_length = _pre.second-_pre.first-left_length;
	printf("call left\n");
	toPostOrder(range(_pre.first+1, _pre.first+1+left_length),
			range(_in.first,_in.first+left_length), pos-right_length);
	printf("call right\n");
	toPostOrder(range(_pre.first+left_length+1,_pre.second),
			range(_in.first+left_length+1, _in.second), pos-1);
	postorder[pos-1] = root_value;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		preorder = vector<int>(n);
		inorder = vector<int>(n);
		postorder = vector<int>(n);

		for( int i = 0 ; i < n ; ++i ){
			scanf("%d",&preorder[i]);
		}
		for( int i = 0 ; i < n ; ++i ){
			scanf("%d",&inorder[i]);
		}
		toPostOrder(range(0,n), range(0,n), n);
		for( int p : postorder ){
			printf("%d ",p);
		}
		printf("\n");
	}
	return 0;
}
