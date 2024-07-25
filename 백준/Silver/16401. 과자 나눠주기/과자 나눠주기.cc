#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
vector<int> v;
int tmp;
int cnt;
int ret;

int check(int mid) {
	int cnt = 0;

	for (int i = v.size() - 1; i >= 0; i--) {
		int std = v[i] / mid;
		cnt += std;
		if (std == 0) break;
	}
	//cout << "mid : " << mid << " cnt : "<< cnt << '\n';
	if (cnt >= n) return 1;
	else return 0;
}



signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int l = 1;
	int r = v[v.size() - 1];
	//cout << l << " " << r << '\n';
	int mid = (l + r) / 2;
	int chk = 0;
	

	while (l <= r) {

		mid = (l + r) / 2;

		chk = check(mid);
		if (chk) {
			l = mid + 1;
			ret = max(ret, mid);
		}

		else {
			r = mid - 1;
		}
	}
	cout << ret;

	


	return 0;
	
}