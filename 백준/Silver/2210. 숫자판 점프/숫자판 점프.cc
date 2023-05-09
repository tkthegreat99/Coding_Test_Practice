#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

//5*5니까.. 전체를 다 탐색한다.
//방문했던 곳을 다시 가도 되니까.. visitied 배열은 필요없고
//vector<int> v 에다가 만약 전에 없던 수라면 새로 추가하고
//있는 거라면 그냥 다음 턴으로 넘어가기.. 반복





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

vector<int> v;
int a[5][5];
string s;

//DFS를 쓰는데, cnt랑 num을 넣어주는거지..
void search(int y, int x, int num, int cnt) {
	
	if (cnt == 6) {
		v.push_back(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		search(ny, nx, num * 10 + a[ny][nx], cnt + 1);
	}
}





int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			search(i, j, 0, 0);
		}
	}

	//벡터의 중복 원소 제거
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	//////////////////////////////////////////////

	

	cout << v.size() << '\n';
	return 0;
}