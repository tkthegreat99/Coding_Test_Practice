#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, a, b;



vector<int> v[10001];
int cnt = 0;
int dp[10001], mx, visited[10001];

void dfs(int here) {
	visited[here] =1;
	int ret = 1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		dfs(there);
		cnt++;
	}
}
//이거 많이 나오니까 외워두기



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(visited, 0, sizeof(visited));

	cin >> n; 
	cin >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << cnt << '\n';

	return 0;
}