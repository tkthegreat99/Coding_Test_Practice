#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
    


int n, m, k;
int tmp;
string str;
int ans[10];

int main() {
    cin >> n >> m >> k;
    tmp = n * m * k;
    str = to_string(tmp);

    for (int i = 0; i < str.size(); i++) {
        ans[str[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << '\n';
    }



}
