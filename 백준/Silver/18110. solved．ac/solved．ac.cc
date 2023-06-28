#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n,m,sum, mn;
float cut;
vector<int> v;



void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
    cin >> n;
}

void solve(){
    if(n == 0){cout << 0; return;}
    cut = floor(0.15 * n + 0.5);
    for(int i = 0 ; i < n; i++){
        cin >> m;
        v.push_back(m);
        sum += m;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i< cut ; i++){
        if(i == n - i - 1) mn += v[i];
        else{
            mn += v[i];
            mn += v[n-i-1];
        }
    }
    int ans = floor(((sum - mn)/(n-(cut*2))) + 0.5);
//    cout << "cut : " << cut << '\n';
//    cout << "sum : " << sum << '\n';
//    cout << "mn : " << mn << '\n';
    cout << ans << '\n';
}
