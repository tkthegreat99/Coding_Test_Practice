#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
int cnt;


void combi(int start, vector<int> b) {
	if (b.size() == k) {
		cnt++;
		return;
	}
	for (int i = start + 1; i <= n; i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}



int main() {
	vector<int> b;
	cin >> n >> k;
	combi(0, b);
	cout << cnt << '\n';


}