#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int a[2200][2200];
int minus_cnt, zero_cnt, plus_cnt;

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


    count(0, 0, n);
    cout << minus_cnt << '\n' << zero_cnt << '\n' << plus_cnt << '\n';
}

void count(int y, int x, int size){

    int std = a[y][x];
    int chk = std;
    for(int i = y ; i < y + size; i++){
        for(int j = x ; j < x + size ; j++){
            if(a[i][j] != std){
                count(y, x, size/3);
                count(y, x + size/3, size/3);
                count(y, x + size*2/3, size/3);

                count(y + size/3, x, size/3);
                count(y + size/3, x + size/3, size/3);
                count(y + size/3, x + size*2/3, size/3);

                count(y + size*2/3, x, size/3);
                count(y + size*2/3, x + size/3, size/3);
                count(y + size*2/3, x + size*2/3, size/3);
                return;
            }
        }
    }
    if(chk == -1) minus_cnt++;
    else if(chk == 0) zero_cnt++;
    else plus_cnt++;
}

