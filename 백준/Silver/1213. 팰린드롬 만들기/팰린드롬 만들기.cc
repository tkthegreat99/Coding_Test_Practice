#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;


int alpha[200];



string s, ret;
char mid;
int flag;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	
	
	cin >> s;
	for (char a : s) alpha[a]++;

	for (int i = 'Z'; i >= 'A'; i--) {
		if (alpha[i]) {
			if (alpha[i] & 1) {
				mid = char(i);
				flag++;
				alpha[i]--;
			}
			if (flag == 2) break;
			for (int j = 0; j < alpha[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}

		}


	}

	if (mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2) cout << "I'm Sorry Hansoo\n";
	else cout << ret << '\n';
	
}

	

