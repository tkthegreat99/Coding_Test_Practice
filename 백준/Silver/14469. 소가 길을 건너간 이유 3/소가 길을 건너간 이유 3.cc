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
int x, y;


int main() {

	fastio;

	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i].first >> a[i].second; }
	sort(a.begin(), a.end());

	int realTime = a[0].first + a[0].second;

	for (int i = 1; i < a.size(); i++) {
		realTime = max(realTime, a[i].first);
		realTime += a[i].second;
	}
	cout << realTime << '\n';
	

	return 0;
}
