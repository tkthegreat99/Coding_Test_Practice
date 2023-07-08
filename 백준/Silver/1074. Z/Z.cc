#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, r, c;
int ret;
void solve();
void Z(int y, int x, int size);

int main(){
    fastio;
    solve();
    return 0;
}

void solve(){
    cin >> n >> r >> c;
    Z(0, 0, (1 << n));
}

void Z(int y, int x, int size){
    if(y == r && x == c){
        cout << ret << '\n';
        return;
    }

    if( r < y + size && r >=y && c < x + size && c >= x){
        Z(y, x, size / 2);
        Z(y, x + size/2, size / 2);
        Z(y + size/2, x, size / 2);
        Z(y + size/2, x + size/2, size / 2);
    }
    else ret += size * size;
}

