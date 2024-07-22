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

int n, tmp;
int psum[100001];
vector<int> v;
int dp[2][100001];
int ret = -1e9;
int mx = -1e9;


signed main() {
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = v[i - 1];
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + v[i - 1];
		mx = max(dp[0][i], dp[1][i]);
		ret = max(mx, ret);
	}

	cout << ret;
}