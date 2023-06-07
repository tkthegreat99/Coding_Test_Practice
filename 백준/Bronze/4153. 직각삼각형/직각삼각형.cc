#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


vector<int> v;
int n;

int main() {
    while (true) {
        
        for (int i = 0; i < 3; i++) {
            cin >> n;
            v.push_back(n);
        }
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) return 0;
        sort(v.begin(), v.end());
        if ((v[2] * v[2]) == (v[1] * v[1]) + (v[0] * v[0])) cout << "right" << '\n';
        else cout << "wrong" << '\n';
        v.clear();
    }
    return 0;
}



    