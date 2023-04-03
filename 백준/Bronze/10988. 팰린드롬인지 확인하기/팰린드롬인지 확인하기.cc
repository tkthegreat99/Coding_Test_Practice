#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int alpha[26];


string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string tmp;

	cin >> s;

	tmp = s;
	reverse(s.begin(), s.end());
	if (tmp == s) cout << 1;
	else cout << 0;

}