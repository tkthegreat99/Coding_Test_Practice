#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n;
int t, time_a, time_b, score_a, score_b;
string tmp;
int h, m, sh, sm;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> t;
		cin >> tmp;
		h = stoi(tmp.substr(0, 2));
		m = stoi(tmp.substr(3, 5)); 
		if (i!=0) {
			if (score_a > score_b) time_a += ((h - sh) * 60 + (m - sm));
			else if (score_a < score_b) time_b += ((h - sh) * 60 + (m - sm));
		}
		if (t == 1) score_a++;
		if (t == 2) score_b++;
		sh = h;
		sm = m;
		if (i == n - 1) {
			if (score_a > score_b) time_a += ((48 - sh) * 60 - m);
			else if (score_a < score_b) time_b += ((48 - sh) * 60 - m);
		}

	}
	printf("%02d:%02d\n%02d:%02d", time_a / 60, time_a % 60, time_b / 60, time_b % 60);

	return 0;
}