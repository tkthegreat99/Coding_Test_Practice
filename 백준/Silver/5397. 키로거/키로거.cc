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

int T;
string str;
string tmp;


string Solve() {
	string text;
	stack <int> stk, temp;

	cin >> text;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '<') {
			if (stk.empty()) continue;
			else {
				temp.push(stk.top());
				stk.pop();
			}
		}
		else if (text[i] == '>') {
			if (temp.empty()) continue;
			else {
				stk.push(temp.top());
				temp.pop();
			}
		}
		else if (text[i] == '-') {
			if (stk.empty()) continue;
			else stk.pop();
		}
		else
			stk.push(text[i]);
	}

	string result;
	while (!temp.empty()) {
		stk.push(temp.top());
		temp.pop();
	}
	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

signed main() {
	fastio;

	cin >> T;

	while (T--) {
		cout << Solve() << '\n';
	}

	return 0;
}