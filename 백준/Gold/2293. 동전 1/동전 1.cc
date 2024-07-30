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


int n, k;
int dp[10001];

signed main() {
	fastio;

	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;	
	for (int i = 0; i < n; i++) { 
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k] << '\n';
	return 0;
}