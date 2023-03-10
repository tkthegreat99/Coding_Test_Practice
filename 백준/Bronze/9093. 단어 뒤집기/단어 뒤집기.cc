#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> reversesplit(string input, string deli) {
	vector<string> ret;
	long long pos = 0;
	string token = "";

	while ((pos = input.find(deli)) != string::npos) {
		token = input.substr(0, pos);
		reverse(token.begin(), token.end());
		ret.push_back(token);
		input.erase(0, pos + deli.length());
	}
	reverse(input.begin(), input.end());
	ret.push_back(input);
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	string buffer;
	string s;

	vector<string> ans;

	getline(cin, buffer);
	for (int i = 0; i < T; i++) {
		getline(cin, s);
		ans = reversesplit(s, " ");
		for (auto a : ans) {
			cout << a << " ";
		}
		cout << '\n';
	}
	return 0;
}