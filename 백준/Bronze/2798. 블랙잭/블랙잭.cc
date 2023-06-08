#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tot, tmp;
vector<int> b;
vector<int> v;
int mx = -987654321;




void combi(int start, vector<int> b) {
    if (b.size() == 3) {
        
        if ((b[0] + b[1] + b[2]) <= m){
            mx = max(mx, (b[0] + b[1] + b[2]));
            return;
        }
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(v[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    combi(0, b);
    cout << mx << '\n';
}


    