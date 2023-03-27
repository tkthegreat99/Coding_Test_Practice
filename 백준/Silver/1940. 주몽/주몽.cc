#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;


int a[15000];



int n, m;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == m) cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
	
	
	
}

	

