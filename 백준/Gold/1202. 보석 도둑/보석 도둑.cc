#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;



/* 사용 함수 */
void input();
void solve();

/* 사용 변수 */

typedef long long ll;
ll n, k, ret, tmp1, tmp;



int main() {
	fastio;
	input();
	//solve();
	return 0;
}

void input() {
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	vector<ll> vv(k);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++) cin >> vv[i];
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	priority_queue <ll> pq;
	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}
	cout << ret << '\n';
}


void solve() {
	
}
