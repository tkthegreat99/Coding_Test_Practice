#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, t, cnt;
int a[15][15];

void input();
void solve();

int main(){
    fastio;
    input();
//    solve();
    return 0;
}
void input(){
    for(int i = 0 ; i < 15; i++){
        a[i][0] = 1;
    }
    for(int i = 0 ; i < 15; i++){
        a[0][i] = i + 1;
    }
    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){

            for(int k = 0; k <= j; k++){
                a[i][j] += a[i-1][k];
            }
        }
    }


    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> n;
        cin >> m;
        cout << a[n][m-1] << '\n';
    }

}

void solve(){

}
