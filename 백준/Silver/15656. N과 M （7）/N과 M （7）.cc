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
/* Jeongwon Is Cute And "P.R.E.T.T.Y"  */

int n, m;
vector<int> v;
int tmp;
vector<int> output;


void dfs(int depth) {

	if (depth == m) {
		for (auto i : output) cout << i << " ";
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			output.push_back(v[i]);
			dfs(depth + 1);
			output.pop_back();
		}
	}
}


signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	dfs(0);
	
	return 0;
}

