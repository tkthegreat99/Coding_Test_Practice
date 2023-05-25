#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;


int a[304][304];
int visited[304][304];
const int dy[] = {-1, -1, -2, -2, 1, 1, 2, 2};
const int dx[] = {2, -2, -1, 1, 2, -2, 1, -1};

int n, m, st_x, st_y, tg_x, tg_y;
void input();
void solve();
void bfs(int y, int x, int size);



int main(){
    fastio;
    solve();
    return 0;
}

void input(){
    /**/
}

void solve(){
    cin >> n;
    while(n--){
        cin >> m;
        fill(&visited[0][0] , &visited[0][0] + 304 * 304, 0);
        cin >> st_x >> st_y;
        cin >> tg_x >> tg_y;
        
        if(st_x == tg_x && st_y == tg_y){
            cout << 0 << '\n';
            continue;
        }
        bfs(st_y, st_x, m);
        
        cout << visited[tg_y][tg_x]  << '\n';
    }
}

void bfs(int y, int x, int size){
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= size || nx >= size) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}


