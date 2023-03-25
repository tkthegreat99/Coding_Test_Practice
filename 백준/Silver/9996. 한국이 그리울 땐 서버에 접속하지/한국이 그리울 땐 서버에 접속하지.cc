#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

vector<string> split(string input, string deli) {
	string token = "";
	vector<string> ret;
	long long pos = 0;
	while ((pos = input.find(deli)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + deli.length());
	}
	ret.push_back(input);
	return ret;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;  // n개의 줄
	

	vector<string> v; //저장할 벡터
	string str; //입력받을 패턴
	cin >> str;
	
	v = split(str, "*");


	string input;
	
	for (int i = 0; i < n; i++) {

		cin >> input;
		if (v[0].length() + v[1].length() > input.length()) cout << "NE" << '\n';
		else {
			if (v[0] == input.substr(0, v[0].length()) && v[1] == input.substr(input.length() - v[1].length())) cout << "DA" << '\n';
			else cout << "NE" << '\n';
		}

	}

	
	return 0;
	
}

	

