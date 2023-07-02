#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
const int INF = 987654321;
int n, m, w, n1, n2;
vector<pair<int, int>> adj[1004];
int visited[1004];
queue<int> q;
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
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            cout << " ";
        }
        for(int j = 0 ; j < i + 1 ; j++){
            cout << "*";
        }
        cout << '\n';
    }

    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0 ; j < i + 1 ; j++) cout << " ";
        for(int j = 0 ; j < n - i - 1 ; j++) cout << "*";
        cout << '\n';
    }
}


