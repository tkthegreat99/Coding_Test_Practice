#include <iostream>
#define fastio cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int psum[100001];
int ret = -100004;
int n, k, tmp;

int main() {
	fastio;
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {

		cin >> tmp;

		psum[i] = psum[i - 1] + tmp;
	}

	for (int i = k; i <= n; i++) {

		ret = max(ret, psum[i] - psum[i - k]);
	}

	cout << ret << '\n';

	return 0;
}
