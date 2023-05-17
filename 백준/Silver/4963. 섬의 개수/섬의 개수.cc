
#include <iostream>
#include <cstring>

using namespace std;

int map[50][50], visit[50][50];
int dx[8] = { 1,1,0,-1,-1,-1,0,1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 }; //이동할 좌표값들
int w, h;

void dfs(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if (nX < 0 || nY < 0 || nX >= w || nY >= h || visit[nY][nX] || map[nY][nX] == 0) continue; //범위를 벗어나면 무시
        
        visit[nY][nX] = 1;
        dfs(nY, nX);
        
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    while (1) {
        int cnt = 0;
        cin >> w >> h;
        if (!w && !h)break; //0,0을 입력하면 중지
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visit[i][j] && map[i][j]) {
                    visit[i][j] = 1;
                    dfs(i, j);
                    cnt++; 
                }
            }
        }
        cout << cnt << "\n";
        memset(visit, 0, sizeof(visit)); 
    }
}
