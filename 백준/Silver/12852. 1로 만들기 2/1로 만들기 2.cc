#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
int dp[1000001];
int cnt;

signed main() {
	fastio;

	cin >> n;
	fill(dp, dp + 1000001, 1e9);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) { dp[i] = min(dp[i], dp[i / 3] + 1); }
		if (i % 2 == 0) { dp[i] = min(dp[i], dp[i / 2] + 1); }
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[n] << '\n';

	int tmp = n;
	cout << tmp << " ";

	while (1) {
		if (tmp == 1) return 0;

		if (tmp % 3 == 0) {
			if (dp[tmp / 3] + 1 == dp[tmp]) {
				cout << tmp / 3 << " ";
				tmp /= 3;
				if (tmp == 1) return 0;
				continue;
			}
		}
		if (tmp % 2 == 0) {
			if (dp[tmp / 2] + 1 == dp[tmp]) {
				cout << tmp / 2 << " ";
				tmp /= 2;
				if (tmp == 1) return 0;
				continue;
			}
		}
		if (dp[tmp - 1] + 1 == dp[tmp]) {
			cout << tmp - 1 << " ";
			tmp--;
			if (tmp == 1) return 0;
		}
	}
	
}
