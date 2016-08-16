#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2100000000
using namespace std;
int init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];
    else return tree[node] = min(init(arr, tree, node * 2, start, (start + end) / 2), init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int MIN(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return MAX;
    if (left <= start && end <= right)
        return tree[node];
    
    return min(MIN(tree, node * 2, start, (start + end) / 2, left, right), MIN(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<int> arr(100000), tree(300000);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    init(arr, tree, 1, 0, n - 1);
    while (m--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", MIN(tree, 1, 0, n - 1, a - 1, b - 1));
    }
    return 0;
}