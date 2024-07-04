#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;



int n, p, d, ret;
priority_queue<int, vector<int>, greater<>> pq;
vector<pair<int, int>> v;


int main(){

	fastio;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d, p });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {

		pq.push(v[i].second);
		while (pq.size() > v[i].first) pq.pop();
	}
	

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}

	cout << ret;



}
