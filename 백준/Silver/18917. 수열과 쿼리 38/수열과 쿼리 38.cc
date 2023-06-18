#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define MAX 1000000

typedef long long ll;

int n, m, tmp;
ll sum, xor_;

void input();
void solve();
int main() {
    fastio;
    input();
    //solve();
    return 0;
}
void input(){
    cin >> m;
    while(m--){
        cin >> n;
        switch(n){
            case 1:
                cin >> tmp;
                sum += tmp;
                xor_ ^= tmp;
                break;
            case 2:
                cin >> tmp;
                sum -= tmp;
                xor_ ^= tmp;
                break;
            case 3:
                cout << sum << '\n';
                break;
            case 4:
                cout << xor_ << '\n';
                break;
        }
    }
}
