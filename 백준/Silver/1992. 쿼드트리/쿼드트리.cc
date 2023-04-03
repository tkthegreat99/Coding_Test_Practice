#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


typedef long long int ll;
int n;
string s;
char a[101][101];

string quard(int y, int x, int size) {
	if (size == 1) return string(1, a[y][x]);
	char b = a[y][x];
	string ret = "";
	bool flag = 0;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != a[i][j]) {
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}


int main() {
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}
	cout << quard(0, 0, n) << '\n';
}