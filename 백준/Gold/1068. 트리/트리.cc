#include<iostream>
#include<algorithm>
#include<string>
#include<vector>


using namespace std;

int n, r, temp, root;

vector<int> adj[54];

/*
자식 없는게 리프노드
노드 지우는 게 아니라 그냥 탐색을 안 하면 댐
그럼 그 밑에 애들도 못 할 거니까..

*/

int dfs(int here) {
    int ret = 0; // 리프노드의 수
    int child = 0; //
    for (int there : adj[here]) {
        if (there == r) continue;  // 만약 지울 노드라면 continue(탐색 안해버리기)
        ret += dfs(there);
        child++; // 자식 노드 개수 세기
    }
    if (child == 0) return 1; // 만약에 자식노드가 없으면 return 1
    //그럼 밑에 애들 다 1 1 1 1 될거고.. 그 위에 애들은 1 + 1 = 2 될거구..2 +2 = 4
    // -> 결국 리프노드 개수가 되겠네..

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1)root = i;
        else adj[temp].push_back(i);
    }

    cin >> r;
    if (r == root) {
        cout << 0 << "\n"; return 0; // 지울 노드가 루트노드면 
    }
    cout << dfs(root) << "\n";
    return 0;
}
