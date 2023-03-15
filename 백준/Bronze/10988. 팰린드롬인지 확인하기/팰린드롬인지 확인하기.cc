#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;



int check(string str) {

	string cop = "";
	cop += str;

	
	reverse(str.begin(), str.end());
	
	int chk = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != cop[i]) chk = 0;
	}
	if (chk == 0) {
		return 0;
	}

	else return 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	getline(cin, str);

	cout << check(str) << '\n';





}