#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
int mx = -1e9;
int a[100001];
int tot;
int ret = 1e9;

int check(int mid) {
	int cnt = 1;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += a[i];
		if (tmp > mid) {
			cnt++;
			tmp = a[i];
		}
		if (cnt > m) return 0; // 블루레이 수보다 나눠진 강의수가 많음.
	}
	if (cnt <= m) return 1;
}




int main() {

	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
		mx = max(a[i], mx);
	}

	int l = mx;
	int r = tot;
	int mid = (l + r) / 2;

	while (l <= r) {

		mid = (l + r) / 2;

		int tmp = check(mid);

		if (tmp) {
			r = mid - 1;
			ret = min(ret, mid);
		}

		else l = mid + 1;
	}


	cout << ret;
	




}