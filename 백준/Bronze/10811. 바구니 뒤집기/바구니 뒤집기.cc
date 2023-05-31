#include<iostream>
#include<vector>
#include<algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;


int n, m, tmp, tmp2;
vector<int> v;


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	while (m--) {
		cin >> tmp >> tmp2;
		reverse(v.begin() + tmp - 1, v.begin() + tmp2 );
	}
	for (int k : v) cout << k << ' ';


}