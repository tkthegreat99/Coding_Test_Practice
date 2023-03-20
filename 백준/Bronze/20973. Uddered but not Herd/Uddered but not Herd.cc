#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	string cow;
	string word;
	int cnt = 0;

	
	getline(cin, cow);
	getline(cin, word);
	int k = 0;

	int len = word.length();

	while (k < len ) {
		for (int i = 0; i < cow.length(); i++) {
			if (cow[i] == word[k]) {
				k++;
			}
		}
		cnt++;
	}

	cout << cnt << '\n';
}