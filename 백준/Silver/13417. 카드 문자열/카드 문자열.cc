#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#pragma warning(disable: 4996)

using namespace std;

int t, n;
vector<string> v;
string s;
string tmp;





void printV(vector<string> v) {
	for (auto c : v) {
		cout << c << '\n';
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t; 
	string tmp;

	while (t--) {
		cin >> n;
		s = "";
		for (int i = 0; i < n; i++) {
			cin >> tmp;
		
			if (i == 0) { 
				s += tmp;
				continue; 
			}
			
			if (s[0] < tmp[0]) {
				s += tmp[0];
			}
			else {
				s = tmp[0] + s;
			}
			
		}

		v.push_back(s);

		
	}


	printV(v);

	return 0;

}



