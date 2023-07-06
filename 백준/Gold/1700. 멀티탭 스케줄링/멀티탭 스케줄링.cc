#include <iostream>
#include <algorithm>
#include <vector>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tmp, cnt;
bool flag = false;
vector<int> v;
int tap[104];

void input();
void solve();

int main() {
    fastio;
    input();
    solve();


    return 0;
}
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

}

void solve() {
    for (int i = 0; i < m; i++) {
        flag = false;

        //이미 해당 플러그가 있을 경우
        for (int j = 0; j < n; j++) {
            if (tap[j] == v[i]) {
                flag = true;
                break;
            }
        }

        if (flag) continue;
        //빈 칸있는 경우
        for (int j = 0; j < n; j++) {
            if (tap[j] == 0) {
                tap[j] = v[i];
                flag = true;
                break;
            }
        }

        //빈칸 없을 때
        if (!flag) {
            int ln = -1;
            int idx = -1;
            for (int j = 0; j < n; j++) {
                int tp = 0;
                for (int k = i + 1; k < m; k++) {
                    if (v[k] == tap[j]) break;
                    tp++;
                }
                if (tp > ln) {
                    ln = tp;
                    idx = j;
                }
            }
            tap[idx] = v[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}
