#include <iostream>
#define fastio cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n;
string ptn, str;

int main() {
	fastio;
	
	cin >> n;

	cin >> ptn;

	auto it = ptn.find("*");
	string pt1 = ptn.substr(0, it);
	string pt2 = ptn.substr(it + 1);

	int chk = 1;
	
	for (int i = 0; i < n; i++) {

		cin >> str;

		if (str.length() < pt1.length() + pt2.length()) chk = 0;
		else {

			if (str.substr(0, pt1.length()) == pt1 && str.substr(str.length() - pt2.length()) == pt2) chk = 1;
			else chk = 0;
		}

		if (chk) cout << "DA" << '\n';
		else cout << "NE" << '\n';

	}


	return 0;
}
