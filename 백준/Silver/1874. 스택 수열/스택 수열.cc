#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

stack<int> st;
vector<char> res;
int cnt = 1;
int n;



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
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(cnt <= x){
            st.push(cnt);
            cnt++;
            res.push_back('+');
        }
        if(st.top() == x){
            st.pop();
            res.push_back('-');
        }
        else {
            cout << "NO";
            return;
        }
    }
    for(int i = 0 ; i  < res.size(); i++){
        cout << res[i] << '\n';
    }
}
