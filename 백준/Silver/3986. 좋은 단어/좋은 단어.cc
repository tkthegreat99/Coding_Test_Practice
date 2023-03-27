#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <stack>






using namespace std;


int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
		
	int cnt = 0;
	cin >> n;
	while (n--) {
		stack<int> st;
		cin >> s;
		st.push(s[0]);
		for (int i = 1; i < s.size(); i++) {
			if (!st.empty() && st.top() == s[i]) {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
		if (st.empty()) cnt++;
	}

	cout << cnt << '\n';
	return 0;
}

	

