#include <iostream>
#include <vector>



using namespace std;


int n, m, cnt, cnt2;
int visited[104][104];
int a[104][104];
vector<pair<int, int>> v;


const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


void go(int y, int x) {
	visited[y][x] = 1; // 방문하면 방문했다고 표시
	if (a[y][x] == 1) {//치즈라면, 
		v.push_back({ y, x }); //y, x를 벡터에 담기.
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		go(ny, nx);
	}
	return;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//n 세로
	//m 가로

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	//치즈가 모두 사라질 때까지 계속 반복, visited 배열을 계속 초기화
	//계속 새로 탐색을... 하는거지.
	//그리고 벡터도 계속 초기화하고, 
	while (true) {
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		go(0, 0);
		cnt2 = v.size(); //벡터에 쌓여진 수가 곧 치즈 갯수
		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0;
			// 벡터에 담은 애들... 즉 b.first, b.second가 y, x니까
			// 곧 치즈를 녹이는 것이지
		}
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) flag = 1; //치즈가 있는지 확인
			}
		}
		cnt++;
		if (!flag) break;
	}

	cout << cnt << '\n' << cnt2 << '\n';
	return 0;
}


