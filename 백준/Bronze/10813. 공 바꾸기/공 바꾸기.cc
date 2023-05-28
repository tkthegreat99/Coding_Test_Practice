#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <tuple>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int a[101];
int n, m, _a, _b;
void input();
void swap(int i, int j);
void solve();

int main() {
	fastio;
	input();
	solve();
	return 0;	
}

void input() {
	cin >> n >> m;
	for (int i = 1;  i <= n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> _a >> _b;
		swap(_a, _b);
	}
	
}
void swap(int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void solve() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
}


