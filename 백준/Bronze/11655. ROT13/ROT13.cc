#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {

		if (str[i] >= 65 && str[i] < 97) {
			if (str[i] + 13 > 90) str[i] -= 13;
			else str[i] += 13;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			if (str[i] + 13 > 122) str[i] -= 13;
			else str[i] += 13;
		}
		

	}
	cout << str;
}

	

