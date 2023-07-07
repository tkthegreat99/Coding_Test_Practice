#include <iostream>
#include <algorithm>
#include <queue>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, a, b, cnt, ipt;

void input();
void solve();

int main(){
    fastio;
    solve();
    return 0;
}

void solve(){
    cin >> n;
    a = n / 5;
    while(1){
        if( a< 0){
            cout << -1 << '\n';
            return;
        }
        if((n - (5 * a)) % 3 == 0){
            b = (n - (5 * a))/3;
            break;
        }
        a--;
    }
    cout << a + b << '\n';
}
