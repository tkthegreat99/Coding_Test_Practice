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
int w, v;
vector<pair<int, int>> V;
int dp[100001];

signed main() {
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		V.push_back({ w, v });
	}

	sort(V.begin(), V.end());

	

	for (int i = 0; i < n; i++) {
		w = V[i].first;
		v = V[i].second;
		for (int j = k; j >= w; j--) {
			//cout << "dp[" << j << "] 랑 dp[" << j << "-" << w << "] + " << v << "를 비교" << '\n';
			dp[j] = max(dp[j], dp[j - w] + v);
			//cout << "dp[" << j << "] = " << dp[j] << '\n';
		}
	}

	cout << dp[k] << '\n';
	
	return 0;
    //by 쩡우이
}