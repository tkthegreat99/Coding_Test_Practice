#include <iostream>
#define fastio cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;





int main() {
	fastio;
	//65 , 97
	string str;

	getline(cin, str);
	for (char s : str) {

		if (isalpha(s)) {
			if (s < 'a') {
				s = 'A' + (s - 'A' + 13) % 26;
				cout << s;
			}
			else {
				s = 'a' + (s - 'a' + 13) % 26;
				cout << s;
			}
		}
		else cout << s;
	}

}
