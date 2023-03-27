	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <string>
	#include <queue>
	#include <map>

	using namespace std;


	int n, m;
	string s;
	map<string, int> mp;
	
	string a[100004];

	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(nullptr); cout.tie(nullptr);

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			mp[s] = i + 1;
			a[i + 1] = s;
		}
		for (int i = 0; i < m; i++) {
			cin >> s;
			if (atoi(s.c_str()) == 0) {
				cout << mp[s] << '\n';
			}
			else {
				cout << a[atoi(s.c_str())] << '\n';
			}
		}
		
	}

	

