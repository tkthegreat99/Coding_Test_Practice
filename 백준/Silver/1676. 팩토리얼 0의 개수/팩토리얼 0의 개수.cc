#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n, tmp, cnt;


int main() {
	fastio;
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			tmp = i;
			while (tmp % 5 == 0 && tmp != 1) {
				tmp /= 5;
				cnt++;
				
			}
		}
	}
	cout << cnt;
}

