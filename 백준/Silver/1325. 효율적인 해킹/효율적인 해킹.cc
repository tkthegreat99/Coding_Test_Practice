#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, a, b;



vector<int> v[10001];
int dp[10001], mx, visited[10001];

int dfs(int here) {
	visited[here] =1;
	int ret = 1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		ret += dfs(there);
	}
	return ret;
}
//이거 많이 나오니까 외워두기



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[b].push_back(a); //그래프 만들기
	}
	for (int i = 1; i <= n; i++) {//모든 정점 탐색
		memset(visited, 0, sizeof(visited)); //테스트 케이스마다 초기화
		dp[i] = dfs(i);//dfs를 dp배열에 담아놓기
		mx = max(dp[i], mx);
	}
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " ";
	//최대값 오름차순으로 출력하기(번호니까 그냥 앞에서부터 같은거)
	

	return 0;
}