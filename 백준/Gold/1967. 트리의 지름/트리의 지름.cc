#include <iostream>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <queue>

#define MAX 1e16
using namespace std;

int n, res, endP;
int a, b, c;
vector<pair<int, int>> node[10004];
int visited[10004];

void dfs(int, int);


int main(){
    fastio;
    cin >> n;
    for(int i = 0 ; i < n - 1; i++){
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    dfs(1, 0);
    res = 0;
    fill(visited, visited +  10004, 0);
    dfs(endP, 0);
    cout << res;

}




void dfs(int p, int len){
    if(visited[p]) return;

    visited[p] = 1;
    if(res < len){
        res = len;
        endP = p;
    }

    for(int i = 0 ; i < node[p].size(); i++){
        dfs(node[p][i].first, len + node[p][i].second);
    }
}
