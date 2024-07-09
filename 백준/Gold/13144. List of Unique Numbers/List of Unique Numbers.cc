#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, tmp;
long long ret;

set<long long> S;
vector<long long> v;

int main() {

	fastio;

	

	cin >> n;

	int s = 0, e = 0;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	while (s < n) {

		if (e < n && S.find(v[e]) == S.end()) {
			S.insert(v[e]);
			e++;
		}
		
		else {
			ret += e - s;
			S.erase(v[s]);
			s++;			
		}

	}
	
	cout << ret;


}