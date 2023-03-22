#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c;

	int ar[100];
	fill(ar, ar + 100, 0);
	

	cin >> a >> b >> c;


	int dep, arr;

	for (int i = 0; i < 3; i++) {
		cin >> dep >> arr;
		for (int j = dep; j < arr; j++) {
			ar[j]++;
		}
	}

	int tot = 0;
	for (int i = 0; i < 100; i++) {
		if (ar[i] == 1) {
			tot += a * ar[i];
		}
		else if (ar[i] == 2) {
			tot += b * ar[i];
		}
		else if (ar[i] == 3) {
			tot += c * ar[i];
		}
	}
	cout << tot << '\n';
}

	

