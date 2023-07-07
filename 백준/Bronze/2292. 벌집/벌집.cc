#include <iostream>
#include <algorithm>
#include <queue>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, t, cnt, ipt;

void input();
void solve();

int main(){
    fastio;
//    input();
    solve();
    return 0;
}
void solve(){
    int num;
    cin >> num;
    int i = 0 ;

    for(int sum = 2; sum <= num; i++) sum += 6*i;
    if(num == 1) i = 1;
    cout << i << '\n';
}
