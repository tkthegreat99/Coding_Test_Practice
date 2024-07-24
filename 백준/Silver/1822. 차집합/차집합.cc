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

int nA, nB;
int tmp;
vector<int> vA;
vector<int> vB;
vector<int> ret;
int chk;


signed main() {
	fastio;

	cin >> nA >> nB;
	for (int i = 0; i < nA; i++) {
		cin >> tmp;
		vA.push_back(tmp);
	}
	for (int i = 0; i < nB; i++) {
		cin >> tmp;
		vB.push_back(tmp);
	}

	sort(vB.begin(), vB.end());

	
	
	for (int i = 0; i < nA; i++) {
		int l = 0;
		int r = vB.size() - 1;
		int mid = (l + r) / 2;
		
		chk = 0;

		while (l <= r) {

			
			mid = (l + r) / 2;

			if (vB[mid] < vA[i]) {
				l = mid + 1;
			}
			else if (vB[mid] > vA[i]) {
				r = mid - 1;
			}
			else {
				chk = 1;
				break;
			}
		}
		if (!chk) ret.push_back(vA[i]);
	}
	if(ret.size()) sort(ret.begin(), ret.end());


	cout << ret.size() << '\n';
	for (auto i : ret) cout << i << " ";

	return 0;
}