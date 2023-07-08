#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int white_cnt, blue_cnt;
int a[128][128];
void solve();
void count(int y, int x, int size);

int main(){
    fastio;
    solve();
    return 0;
}

void solve(){
    cin >> n;
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < n; j++)
            cin >> a[i][j];

    //맨 왼쪽 위 색깔에 대해 전체가 모두 0인지, 1인지 확인한다.
    //만약 모두 0이면, white_cnt를 ++하고 종료한다.
    //만약 모두 1이면, blue_cnt를 ++하고 종료한다.
    //그렇지 않다면, 한 변이 2/n 인 사각형에 대해 다시 한번 검사한다.
    //이를 반복한다. 모두 종료되면, 반복을 중단한다.
    count(0, 0, n);
    cout << white_cnt << '\n' << blue_cnt << '\n';
}

void count(int y, int x, int size){
    //y, x는 현재 탐색하고자 하는 사분면의 가장 왼쪽 위의 좌표.
    int chk = a[y][x];
    for(int i = y ; i < y + size; i++){
        for(int j= x; j < x + size; j++){
            if(chk == 0 && a[i][j] == 1) chk = 2;
            else if (chk == 1 && a[i][j] == 0) chk = 2;

            if(chk == 2){
                count(y, x, size/2);
                count(y, x + size/2, size / 2);
                count(y + size / 2, x, size / 2);
                count(y + size/2, x + size/2, size/2);
                return;
            }
        }
    }
    if(chk == 0) white_cnt++;
    else blue_cnt++;
}
