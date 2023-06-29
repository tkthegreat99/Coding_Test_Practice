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

void combi(int start, vector<int> b);
void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
    cin >> n >> m;
}

void solve(){
    combi(0, v);
}

void combi(int start, vector<int> b){
    if(b.size() == m){
        for(int k : b) cout << k << " ";
        cout << '\n';
    }
    for(int i = start + 1; i <=n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}
