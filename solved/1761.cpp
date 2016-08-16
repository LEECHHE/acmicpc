#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef struct node{
    int level;
    struct node* parent;
    int cost;
    vector<pair<node*,int>> child;
    
    node(){
        parent = NULL;
        cost = 0;
    }
}node;
vector<node> nodes;
void traverse(node* cur, int lvl){
    (*cur).level = lvl;
    for( auto ch : (*cur).child ){
        if(ch.first->level > 0){
            cur->parent = ch.first;
            cur->cost = ch.second;
        }
        else{
            traverse(ch.first, lvl+1);
        }
    }
}
int main(){
    int n; scanf("%d",&n);
    nodes = vector<node>(n+1, node());
    for( int i = 1 ; i < n ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        nodes[a].child.push_back(make_pair(&nodes[b],c));
        nodes[b].child.push_back(make_pair(&nodes[a], c));
    }
    traverse(&nodes[1], 1);
    int m; scanf("%d",&m);
    while(m--){
        int l,r; scanf("%d%d",&l,&r);
        node* left = &nodes[l], *right = &nodes[r];
        int ret = 0;
        while(left!=right){
            if(left->level == right->level){
                ret += left->cost+right->cost;
                left = left->parent;
                right = right->parent;
                continue;
            }
            if(left->level < right->level ){
                ret += right->cost;
                right = right->parent;
            }
            else if(left->level > right->level ){
                ret += left->cost;
                left = left->parent;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}