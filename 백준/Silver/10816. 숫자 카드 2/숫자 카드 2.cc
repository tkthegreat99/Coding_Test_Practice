#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tmp;

map<int, int> t;
vector<int> v;

void input();

int main() {
	fastio;
	input();
	return 0;
}



void input() {
	cin >> n;
	while (n--) {
		cin >> tmp;
		t[tmp]++;
	}
	cin >> m;
	while (m--) {
		cin >> tmp;
		auto item = t.find(tmp);
		if (item == t.end()) cout << 0 << ' ';
		else cout << t[tmp] << ' ';
	}

}