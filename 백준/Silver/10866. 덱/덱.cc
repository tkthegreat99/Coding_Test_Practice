#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, a, b;


/*
vector<int> v[10001];
int cnt = 0;
int dp[10001], mx, visited[10001];

void dfs(int here) {
	visited[here] =1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		dfs(there);
		cnt++;
	}
}
*/

deque<int> q;
string tmp;





int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	while (n--) {
		cin >> tmp;
		if (tmp == "push_back") {
			cin >> m;
			q.push_back(m);
		}
		else if (tmp == "push_front") {
			cin >> m;
			q.push_front(m);
		}
		else if (tmp == "front") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front()<< '\n';
		}
		else if (tmp == "back") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.back() << '\n';
		}
		else if (tmp == "size") {
			cout << q.size() << '\n';
		}
		else if (tmp == "pop_front") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
			q.pop_front();
		}
		else if (tmp == "pop_back") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.back() << '\n';
			q.pop_back();
		}
		else if (tmp == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}

	return 0;
}