#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long

#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;



int x, y;
int ret = LLONG_MAX - 1;


signed main() {

	fastio;
	
	cin >> x >> y;

	

	int OriginalRate = (int)((double)y * 100 / (double)x);

	if (OriginalRate >= 99) {
		cout << -1;
		return 0;
	}

	int l = 1;
	int r = LLONG_MAX - 1;
	int mid = (l + r) / 2;

	while (l <= r) {

		mid = (l + r) / 2;
		//cout << "l : " << l << " r : " << r << '\n';
		//cout << mid << '\n';
		// 만약 승률이 바뀌지 않았다면 => 게임을 더 많이 해야된다. higher
		if ((int)((double)(y + mid) * 100 / (double)(x + mid)) == OriginalRate) {

			l = mid + 1;
		}

		//만약 승률이 바뀌었다면 최소를 찾자
		else {
			r = mid - 1;
			//cout << "ret : " << ret << '\n';
			ret = min(ret, mid);
		}
	}

	if (l <= r && ((int)((double)(y + mid) * 100 / (double)(x + mid)) == OriginalRate)) {
		ret = -1;
	}

	cout << ret;
	

	return 0;
}