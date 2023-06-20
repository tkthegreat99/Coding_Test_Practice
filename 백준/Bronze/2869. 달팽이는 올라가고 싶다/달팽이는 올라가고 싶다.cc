#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define MAX 1000000

int n, m, cur, cnt, v;


void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
    cin >> n >> m >> v;
}

void solve(){
    cnt = 1;
    cnt += (v-n) / (n-m);
    if((v-n) % (n-m) != 0) cnt ++;
    if(n >= v) cout << "1";
    else cout << cnt;
}
