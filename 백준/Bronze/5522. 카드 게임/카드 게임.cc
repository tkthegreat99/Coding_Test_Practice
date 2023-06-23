#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n, m;




void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
   for(int i = 0 ; i < 5; i++){
       cin >> n;
       m += n;
   }
}

void solve(){
    cout << m << '\n';
}
