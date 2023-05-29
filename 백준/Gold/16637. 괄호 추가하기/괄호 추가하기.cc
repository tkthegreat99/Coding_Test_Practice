#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <tuple>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, ret = -987654321;
void input();
void solve(int here, int _num);
int oper(char a, int b, int c);
string s;

vector<int> num;
vector<char> oper_str;

int main() {
	fastio;
	input();
	solve(0, num[0]);
	cout << ret << '\n';
	return 0;	
}

void input() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper_str.push_back(s[i]);
	}
}

void solve(int here, int _num) {
	/*cout << here << " : " << _num << '\n';*/
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	solve(here + 1, oper(oper_str[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1) {
		int tmp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
		solve(here + 2, oper(oper_str[here], _num, tmp));
	}
	return;
}

int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}


