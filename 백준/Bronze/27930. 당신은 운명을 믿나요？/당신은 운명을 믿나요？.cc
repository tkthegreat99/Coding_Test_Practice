#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;


string s;
string s1 = "YONSEI";
string s2 = "KOREA";




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> s;
	int chk1 = 0;
	int chk2 = 0;
	int po1 = 0;
	int po2 = 0;

	int turn1;
	int turn2;


	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s1[chk1]) {
			chk1++;
			if (chk1 == 6) { po1 = 1; turn1 = i;}
		}
		if (s[i] == s2[chk2]) {
			chk2++;
			if (chk2 == 5) { po2 = 1; turn2 = i; }
		}


	}
	
	if (po1 && po2) {
		if (turn1 > turn2) {
			cout << "KOREA" << '\n';
		}
		else cout << "YONSEI" << '\n';

	}
	else {
		if (po1 == 1) cout << "YONSEI" << '\n';
		else cout << "KOREA" << '\n';
	}

	
	return 0;

}



