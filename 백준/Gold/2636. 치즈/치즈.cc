#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;



int a[104][104];
int visited[104][104];
int n, m, ret, cnt2, cnt;


const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> v;

void go(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        v.push_back({ y, x }); //1이야? 치즈네 치즈 담기
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
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();
        go(0, 0);
        cnt2 = v.size();
        for (pair<int, int> b : v) {
            a[b.first][b.second] = 0;  //치즈 녹이기
        }
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) flag = 1;   //치즈가 있는지 확인
            }
        }
        cnt++;
        if (!flag) break; //치즈 없으면 break

    }

    cout << cnt << '\n' << cnt2 << '\n';
   

    return 0;
}