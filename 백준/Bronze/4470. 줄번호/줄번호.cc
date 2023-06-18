#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define MAX 1000000

string str;
vector<string> v;
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
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, str);
        v.push_back(str);
    }
}

void solve(){
    for(int i = 0; i < v.size(); i++){
        cout << i + 1 << ". " << v[i] << '\n';
    }
}