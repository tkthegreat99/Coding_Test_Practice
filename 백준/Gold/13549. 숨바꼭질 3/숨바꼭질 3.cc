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
int a, b;
int visited[100004];

int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> a >> b;
    if(a == b){
        cout << 0 << '\n';
        return;
    }
    if(b == 0){
        cout << a << '\n';
        return;
    }
    bfs();
}

void bfs(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, a});
    int time, here;
    while(pq.size()){
         tie(time, here) = pq.top();
         if(b == here){
             cout << pq.top().first << '\n';
         }

         pq.pop();

        if (here * 2 <= 100000 && !visited[here * 2]){
            visited[here * 2] = 1;
            pq.push({time, here *2});
        }
        if(here - 1 >= 0 && !visited[here - 1]) {
            visited[here - 1] = 1;
            pq.push({time + 1, here - 1});
        }
        if(here + 1 <= 100000 && !visited[here + 1]){
            visited[here + 1] = 1;
            pq.push({time + 1, here + 1});
        }

    }
}
