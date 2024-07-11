#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


int T, n, m;
int num;
int ret = -1e9;
int arr[20001], arr2[20001];

int main() {

	fastio;

	cin >> T;

	while (T--) {
		int tot = 0;
		fill(arr, arr + 20001, 0);
		fill(arr2, arr2 + 20001, 0);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		
		sort(arr2, arr2 + m);

		int l = 0;
		int r = m - 1;
		int mid = (l + r) / 2;

		for (int i = 0; i < n; i++) {
			l = 0;
			r = m - 1;
			ret = -1;
			while (l <= r) {

				mid = (l + r) / 2;

				//cout << "mid : " << mid << '\n';
				//cout << " arr[i] : " << arr[i] << "arr2[mid] : " << arr2[mid] <<'\n';

				if (arr2[mid] < arr[i]) {
					l = mid + 1;
					ret = max(ret, mid);

				}
				else {
					r = mid - 1;
				}

			}
			tot += ret + 1;
		}

		cout << tot << '\n';

	}




	
}