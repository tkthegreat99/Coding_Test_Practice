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
//#define int long long

#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


/*

연종이 -> 하루동안 본 정수 모두 기억
연종이가 본 정수들을 수첩 1에 모두 적어놈

동규는 연종에게 M개의 질문
동규는 연종이 봣다고 주장하는 수들을 수첩 2에 적어놓음

*/

int t, n, m, x;
int note1[1000001];
int note2[1000001];

int main() {

	fastio;

	cin >> t;

	while (t--) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> note1[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> note2[i];
		}

		sort(note1, note1 + n);

		// note 1 : 1 2 3 4 5
		// note 2 : 1 3 7 9 5

		// n = 5

		for (int i = 0; i < m; i++) {
			int chk = 0;

			int l = 0; //1
			int r = n-1; // 5

			int mid = (l + r) / 2;

			while (l <= r) {

				mid = (l + r) / 2; //3

				if (note2[i] < note1[mid]) {
					r = mid - 1;
				}
				else if (note2[i] > note1[mid]) {
					l = mid + 1;
				}
				else if (note2[i] == note1[mid]) {
					cout << 1 << '\n';
					chk = 1;
					break;
				}
			}
			if (chk == 0) cout << 0 << '\n';
		}


	}

}