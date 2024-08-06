#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, W, L;
int truck[1001];
int t;
int bridge[101];
int turn;

/*

7 4 5 6

0 7
7 0
0 4
4 5
5 0
0 6
6 0
0 0

*/

void moveforwardOne() {
	for (int i = 0; i < W - 1; i++) {
		bridge[i] = bridge[i + 1];
	}
}

int weight() {
	int tmp = 0;
	for (int i = 0; i < W; i++) {
		tmp += bridge[i];
	}
	return tmp;
}

void move() {
	//cout << weight() + truck[turn] - bridge[0] << '\n';
	if (turn < n && weight() + truck[turn] - bridge[0] <= L) {
		moveforwardOne();
		t++;
		bridge[W - 1] = truck[turn];
		turn++;
	}
	else {
		moveforwardOne();
		bridge[W - 1] = 0;
		t++;
	}
}
int check() {
	for (int i = 0; i < W; i++) {
		if (bridge[i] != 0) return 0;
	}
	return 1;
}



signed main() {
	fastio;

	cin >> n >> W >> L;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	while (1) {
		move();
	

		if (turn == n  && check()) break;
	}
	cout << t;
}

