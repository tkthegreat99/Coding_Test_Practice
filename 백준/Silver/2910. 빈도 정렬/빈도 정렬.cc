#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;


map<int, int> m;
map<int, int> m_seq;
int n, c;
int tmp;



vector<pair<int, int>> v;
vector<pair<int, int>> v2;

vector<int> ret;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return m_seq[a.first] < m_seq[b.first];
	}
	return a.second > b.second;
}




int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> tmp; m[tmp]++;
		if (m_seq[tmp] == 0) m_seq[tmp] = i+1;
	}

	for (auto k : m) {
		v.push_back({ k.first, k.second });
	}
	

	sort(v.begin(), v.end(), cmp);

	for (auto k : v) {
		for (int i = 0; i < m[k.first]; i++) {
			cout << k.first << " ";
		}
	}
	
	

	return 0;
}