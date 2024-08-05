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

int m, n;
string str;
set<string> st;
string tmp;



signed main() {
	fastio;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i];
		st.insert(tmp);
		for (int j = i + 1; j < str.size(); j++) {
			tmp += str[j];
			st.insert(tmp);
		}
	}
	cout << st.size();


	
	return 0;
}

