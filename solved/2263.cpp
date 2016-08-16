#include <iostream>
#include <cstring>
using namespace std;

int num_node;
int in_list[100005];
int post_list[100005];
void getTree(pair<int, int> in, pair<int, int> post) {
	if(in.first > in.second)		return;
	if (in.first<0 || post.first<0 || \
		in.second<0 || post.second<0 || \
		in.first >= num_node || post.first >= num_node || \
		in.second>=num_node || post.second>=num_node)	return;
	
	int cur_root = post_list[post.second];
	
	int root_idx=0;
	for(root_idx=in.first; root_idx<in.second; root_idx++) {
		if(cur_root == in_list[root_idx])		break;
	}
	cout<<cur_root<<" ";

	int L = root_idx - in.first;
	getTree(make_pair(in.first, in.first+L-1), \
			make_pair(post.first, post.first+L-1));

	getTree(make_pair(in.first+L+1, in.second), \
			make_pair(post.first+L, post.second-1)); 
	return;
}
int main(void) {

	memset(post_list, -1, sizeof(post_list));
	memset(in_list, -1, sizeof(in_list));
	cin>>num_node;
		
	int cur_val;
	for(int in_iter=0; in_iter<num_node; in_iter++) {
		cin>>cur_val;
		in_list[in_iter] = cur_val;
	}
	for(int post_iter=0; post_iter<num_node; post_iter++) {
		cin>>cur_val;
		post_list[post_iter] = cur_val;
	}
	getTree(make_pair(0, num_node-1), make_pair(0, num_node-1));
	cout<<endl;

	return 0;
}