#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;


vector<string> split(string input, string deli){
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(deli)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + deli.length());
	}
	ret.push_back(input);
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> song;
	string sharksong = "baby sukhwan tururu turu very cute tururu turu in bed tururu turu baby sukhwan";
	song = split(sharksong, " ");
	// 공백으로 분리해서 스트링 벡터에 저장해놓고
	//14개가 계속 반복되면서 tururu랑 turu에만 붙는 거니까...
	//14로 나눴을 때 나머지 3, 4, 7, 8, 11, 12

	int idx = (n - 1) % 14;
	string result = song[idx];
	if (result == "tururu" || result == "turu") {
		for (int i = 0; i < n / 14; i++)
			result += "ru";
		if (result.length() >= 12) result = "tu+ru*" + to_string((result.length() - 2) / 2);
	}
	cout << result;
}