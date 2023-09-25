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
void dfs(int depth);

/* Variable Initialization */
int n, m;
int num;
int arr[10];
vector<int> v;
int cp;
int visited[10];
map<int, int> mp;

int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) {
        cin >> num;
        if(!mp[num]) {
            v.push_back(num);
        }
        mp[num]++;
    }
    sort(v.begin(), v.end());

    dfs(0);
}

void dfs(int depth){
    if(depth == m){
        for(int x : arr){
            if( x != 0) cout << x << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0 ; i < v.size() ; i++){

        if(visited[i] < mp[v[i]]) {
            visited[i]++;
            arr[depth] = v[i];
            dfs(depth + 1);
            visited[i]--;
        }
    }
}


