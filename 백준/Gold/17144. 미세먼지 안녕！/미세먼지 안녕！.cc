#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

/* Method Initialization */
void input();
void solve();

/* Variable Initialization */

int munji[51][51];
int room[51][51];
int r, c, t;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int up_row, down_row, total_dust;

int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> r >> c >> t;
    int flag = 0;
    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> room[i][j];
            if(room[i][j] == -1){
                if(!flag){
                    up_row = i;
                    flag = 1;
                }
                else down_row = i;
            }
            else total_dust += room[i][j];
        }
    }
}

void spread(){
    for(int i = 0 ; i < r; i++){
        for(int j = 0 ; j < c; j++){
            int cnt = 0;
            int val = room[i][j] / 5;
            if(room[i][j] == 0 || room[i][j] == -1) continue;
            for(int k = 0 ; k < 4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                if(room[nr][nc] == -1) continue;
                munji[nr][nc] += val;
                cnt++;
            }
            munji[i][j] -= (cnt * val);
        }
    }

    for(int i =0 ; i < r; i++){
        for(int j = 0 ; j < c; j++){
            room[i][j] += munji[i][j];
            munji[i][j] = 0;
        }
    }
}

void cleaner() {

    total_dust -= room[up_row - 1][0];
    total_dust -= room[down_row + 1][0];

    for(int i = up_row - 1; i > 0; i--)
        room[i][0] = room[i-1][0];

    for (int i = 0; i < c - 1; i++)
        room[0][i] = room[0][i + 1];

    for (int i = 1; i <= up_row; i++)
        room[i - 1][c - 1] = room[i][c - 1];

    for (int i = c - 1; i > 1; i--)
        room[up_row][i] = room[up_row][i - 1];
    room[up_row][1] = 0;

    for (int i = down_row + 1; i < r - 1; i++)
        room[i][0] = room[i + 1][0];

    for (int i = 0; i < c - 1; i++)
        room[r - 1][i] = room[r - 1][i + 1];

    for (int i = r - 1; i >= down_row; i--)
        room[i][c - 1] = room[i - 1][c - 1];

    for (int i = c - 1; i > 1; i--)
        room[down_row][i] = room[down_row][i - 1];
    room[down_row][1] = 0;
}

void solve()
{
    while (t--)
    {
        spread();
        cleaner();
    }
    cout << total_dust << '\n';
}




