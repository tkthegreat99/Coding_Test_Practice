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

int n, tmp, num;
int dp[1004];
vector<int> v;
int ret = 0, mx = 0;



signed main() {
	fastio;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	//1 100 2 50 60 3 5 6 7 8

	dp[0] = 0;
	dp[1] = v[0];
	for (int i = 2; i <= n; i++) {	
		mx = 0;
		for (int j = 1; j < i; j++) {
			if (v[j-1] < v[i-1]) {
				mx = max(mx, dp[j]);
			}
		}
		dp[i] = mx + v[i - 1];
		ret = max(ret, dp[i]);
	}

	cout << max(ret, dp[1]);
	
}