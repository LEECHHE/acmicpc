#include <stdio.h>
#include <deque>
using namespace std;
int n, m, res;
deque <int> deq;
int main() {
  scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) deq.push_back(i);
	int x;
	for (int k = 1; k <= m; k++) {
		scanf("%d",&x);
		if (deq.front() == x) {
			deq.pop_front();
		} else {
			int cnt1, cnt2;
			deque <int> A, B;
			A = deq; B = deq;
			cnt1 = cnt2 = 0;
			while (A.front() != x) {
				A.push_back(A.front());
				A.pop_front();
				cnt1++;
			}
			while (B.front() != x) {
				B.push_front(B.back());
				B.pop_back();
				cnt2++;
			}
			if (cnt1 > cnt2) res += cnt2, deq = B;
			else res += cnt1, deq = A;
			deq.pop_front();
		}
	}
	printf("%d",res);
	return 0;
}