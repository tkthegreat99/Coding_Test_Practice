#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;




string tmp;

vector<string> v;
int is_mother_or_son(char s) {
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return 1;
	else return 0;
}
// 1이면 모음 0 이면 자음



bool is_mother_exist(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (is_mother_or_son(s[i])) return true;
	}
	return false;
}

bool is_not_three(string s) {

	if (s.size() <= 2) return true;



	for (int i = 0; i < s.size() - 2; i++) {
		if (is_mother_or_son(s[i])) {
			if (is_mother_or_son(s[i + 1]) && is_mother_or_son(s[i + 2])) return false;
		}
		else if (!is_mother_or_son(s[i])) {
			if (!is_mother_or_son(s[i + 1]) && !is_mother_or_son(s[i + 2])) return false;
		}
	}
	return true;
}

bool is_not_two(string s) {
	for (int i = 0; i < s.size()-1; i++) {

		if (s[i] == s[i + 1]) {
			if (s[i] == 'e' || s[i] == 'o') return true;
			else return false;
		}
	}
	return true;
}



int main() {
	while (1) {
		cin >> tmp;
		if (tmp == "end") break;
		v.push_back(tmp);
	}

	for (auto s : v) {
		if (is_mother_exist(s) && is_not_three(s) && is_not_two(s)) {
			cout << "<" << s << ">" << " is acceptable." << '\n';
		}
		else {
			cout << "<" << s << ">" << " is not acceptable." << '\n';
		}

	}
	
	
	

	return 0;
}