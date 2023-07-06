#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;


/* 사용 함수 */
void input();
void solve();

/* 사용 변수 */

int from, to, n, idx = 0, ret = 1;
vector<pair<int, int>> v;



int main() {
	fastio;
	input();
	solve();
	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		v.push_back({ to, from });
	}
}
void solve() {
	sort(v.begin(), v.end());
	from = v[0].second;
	to = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second < to) continue;
		from = v[i].second; to = v[i].first; ret++;
	}
	cout << ret << '\n';
}