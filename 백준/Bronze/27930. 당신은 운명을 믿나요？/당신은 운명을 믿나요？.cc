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


	for (auto i : s) {
		if (i == s1[chk1]) {
			chk1++;
			if (chk1 == 6) { cout << "YONSEI" << '\n'; return 0; }
		}
		else if (i == s2[chk2]) {
			chk2++;
			if (chk2 == 5) { cout << "KOREA" << '\n'; return 0; }
		}


	}
	
	
	return 0;

}



