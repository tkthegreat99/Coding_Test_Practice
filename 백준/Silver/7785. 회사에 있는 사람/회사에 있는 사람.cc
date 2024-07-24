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

map<string, bool, greater<>> mp;
int n;
string name, inout;



signed main() {
	fastio;

	cin >> n;
	//getchar();
	for (int i = 0; i < n; i++) {
		cin >> name >> inout;
		//cout << name << " " inout << '\n';
		if (inout == "enter") mp[name] = true;
		else mp[name] = false;
	}

	for (auto i : mp) {
		if(i.second) cout << i.first << '\n';
	}

	
	return 0;
	
}