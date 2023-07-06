#include <iostream>
#include <algorithm>
#include <queue>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, t, cnt, ipt;

void input();
void solve();

int main(){
    fastio;
//    input();
    solve();
    return 0;
}
void input(){
}

void solve(){
    cin >> t;
    for(int i = 0 ; i < t; i++){
        cnt = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int j = 0 ; j < n ; j++){
            cin >> ipt;
            q.push({j, ipt});
            pq.push(ipt);
        }
        while(q.size()){
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                ++cnt;
                if(idx == m){
                    cout << cnt << '\n';
                    break;
                }
            }
            else q.push({idx, value});
        }
    }
}
