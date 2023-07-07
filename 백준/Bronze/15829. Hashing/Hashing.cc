#include <iostream>
#include <algorithm>
#include <string>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, sum;
char c;
vector<char> v;
string str;

void input();
void solve();
int baskin(int k);

int main(){
    fastio;
    solve();
    return 0;
}


int baskin(int k){
    int ret = 1;
    for(int i = 0 ; i < k; i++){
        ret *= 31;
    }
    return ret;
}


void solve(){
    cin >> n;
    cin >> str;
    int ret;
    for(int i = 0 ; i < n; i++){
        v.push_back(str[i]);
    }

    for(int i = 0 ; i < n; i++){
        sum += baskin(i) * (v[i] - '0' - 48);
    }
    ret = sum % 1234567891;
    cout << ret << '\n';
}
