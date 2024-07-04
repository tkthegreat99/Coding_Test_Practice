#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


string str, str2;

int main(){

	fastio;
	
	cin >> str >> str2;

	string tmps = "";

	for (int i = 0; i < str.size(); i++) {
		tmps += str[i];
		if (str[i] == str2[str2.size() - 1]) {
			
			if ((tmps.size() >= str2.size()) && (tmps.substr(tmps.size() - str2.size(), str2.size()) == str2)) {
				
				tmps.erase(tmps.size() - str2.size());

			}
		}
	}
	if (tmps.size() == 0) cout << "FRULA";
	else cout << tmps;

}
