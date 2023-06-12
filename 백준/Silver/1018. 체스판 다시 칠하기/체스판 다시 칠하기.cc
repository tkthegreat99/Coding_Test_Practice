#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tmp;
char a[50][50];
string str;
void input();
int WB_cnt(int  y, int x);
int BW_cnt(int  y, int x);
void solve();

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};


int main() {
	fastio;
	input();
	solve();
	return 0;
}


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j];
		}
	}
}

int WB_cnt(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i + y][j + x] != WB[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}


int BW_cnt(int y, int x) {
	int cnt = 0; 
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[i + y][j+ x] != BW[i][j]) cnt++;
		}
	}
	return cnt;
}

void solve() {
	int cnt_1;
	int cnt_2;
	int mn = 987654321;
	for (int i = 0; i + 8 <= n; i++) {
		for (int j = 0; j + 8 <= m; j++) {
			cnt_1 = WB_cnt(i, j);
			cnt_2 = BW_cnt(i, j);
			tmp = cnt_1 <= cnt_2 ? cnt_1 : cnt_2;
			mn = min(mn, tmp);
		}
	}
	cout << mn << '\n';
}