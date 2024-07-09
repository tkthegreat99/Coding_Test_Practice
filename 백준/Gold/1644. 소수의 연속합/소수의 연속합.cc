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

bool a[4000001];
int n;
vector<int> v;
int ret = 0;

void isprime() {

	a[0] = a[1] = 1;

	//지금 소수가 아니면 1이 되야댐
	//소수면 0이 되야댐

	for (int i = 2; i <= n; i++) {

		if (a[i] == 1) continue;
		v.push_back(i);
		for (int j = i + i; j <= n; j += i) {
			a[j] = 1;
		}
	}
}




int main() {

	fastio;

	cin >> n;
	
	isprime();

	int s, e;

	s = v.size() - 1;
	e = s;
	int tmp = 0;


	

	while (e >= 0) {

		if (s == e) {
			if (v[e] == n) {
				ret++;
				e--;
				if (s > 0) s--;
				continue;
			}
			tmp = v[e];
			if (s > 0) s--;
		}

		if(s != e) tmp += v[s];
		

		if (tmp > n) {
			e--;
			s = e;
		}

		else if (tmp < n) {
			if (s > 0) s--;
			else {
				e--;
				s = e;
			}

		}

		else if (tmp == n) {
			ret++;
			e--;
			s = e;
		}


	}
	
	cout << ret << '\n';


	return 0;
}
