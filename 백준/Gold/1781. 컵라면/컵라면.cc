#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
int a, b;
int ret;


int main() {

	fastio;

	cin >> n;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());





	for (int i = 0; i < v.size(); i++) {
		ret += v[i].second;
		pq.push(v[i].second);


		if (pq.size() > v[i].first) {
			ret -= pq.top();
			pq.pop();

			
		}
	}

	cout << ret << '\n';

	return 0;
}
