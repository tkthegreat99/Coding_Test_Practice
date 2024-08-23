#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;

void star(int y, int x, int n) {

	//cout << n << '\n';

	if ((y / n) % 3 == 1 && (x / n) % 3 == 1) cout << " ";
	else {
		if (n / 3 == 0) cout << "*";
		else star(y, x, n / 3);
	}

}



signed main() {
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << '\n';
	}

	

	return 0;
}

