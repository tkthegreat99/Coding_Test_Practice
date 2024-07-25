#include <iostream>
#include <vector>
using namespace std;

vector<int> a, ans;

int idx_bsearch(int k) {
	int lo = 0, hi = ans.size() - 1, mid;

	while (lo < hi) {
		mid = lo + (hi - lo) / 2;

		if (ans[mid] >= k) 
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}

int main(void) {
	int n, t, idx;

	cin >> n;
	for (int i = 0; i < n; i++) 
	{ cin >> t;  a.push_back(t); }
	ans.push_back(a.front());

	for (int i = 1; i < n; i++) {
		if (a[i] > ans.back())
			ans.push_back(a[i]);
		else {
			idx = idx_bsearch(a[i]);
			ans[idx] = a[i];
		}
	}
	cout << ans.size();

	return 0;
}