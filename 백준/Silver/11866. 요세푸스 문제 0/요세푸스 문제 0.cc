#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#include<queue>

int n, k;
int cnt;
void input();
void solve();
queue<int> q;

int main() {
	fastio;
	input();
	solve();
	return 0;
}

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
}


void solve() {
	cout << "<";

	while (q.size() != 0)
	{
		for (int i = 1; i < k; i++)
		{
			q.push(q.front()); // i번째 카드를 맨뒤로
			q.pop();
		}
		cout << q.front();
		if (q.size() != 1) cout << ", ";
		q.pop();
	}
	cout << ">";
}