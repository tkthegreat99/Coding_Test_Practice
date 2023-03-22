#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int alpha[26];
	fill(alpha, alpha + 26, 0);

	int n;
	cin >> n;
	getchar();
	string f_name;
	vector<char> ret;


	for (int i = 0; i < n; i++) {
		cin >> f_name;
		alpha[f_name[0] - 'a']++;
	}
	int chk = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) { 
			ret.push_back('a' + i);
			chk = 1;
		}
	}
	if (chk == 1) {
		for (auto a : ret) cout << a;
	}
	else cout << "PREDAJA";
	
}

	

