#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

/* Method Initialization */
void input();
void solve();
void bfs();

/* Variable Initialization */
int n, t, a, b;
int visited[10000];

int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> t;
    for(int i = 0; i < t; i++){
        fill(&visited[0], &visited[0] + 10000, 0);
        cin >> a >> b;
        bfs();
    }
}

void bfs(){
    queue<pair<int, string>> q;
    q.push({a, ""});
    visited[a] = 1;
    int here;
    string here_op;
    while(q.size()){
        tie(here, here_op) = q.front();
        q.pop();

        if(here == b)
        {
            cout << here_op << '\n';
            return;
        }

        int D, S, L, R;

        D = (here * 2) % 10000;
        if(!visited[D]) {
            visited[D] = 1;
            q.push({D, here_op + "D"});
        }
        S = here - 1 < 0 ? 9999 : here - 1;
        if(!visited[S]) {
            visited[S] = 1;
            q.push({S, here_op + "S"});
        }
        L = (here % 1000) * 10 + here / 1000;
        if(!visited[L]) {
            visited[L] = 1;
            q.push({L, here_op + "L"});
        }
        R = here / 10 + (here % 10) * 1000;
        if(!visited[R]){
            visited[R] = 1;
            q.push({R, here_op + "R"});
        }
    }
}