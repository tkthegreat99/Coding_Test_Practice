#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tot, tmp;
string str, tmp_str;
int mx = -987654321;

int main() {
	while (true) {
		cin >> n;
		if (n == 0) break;
		str = to_string(n);
		tmp_str = str;
		reverse(str.begin(), str.end());
		if (tmp_str == str) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}