#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;





int f, s, g, u, d;
int visited[1000004];
int dfloor[2];
int chk;



signed main() {
	fastio;
	//fill(visited, visited + 1000004, -1);
	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << 0;
		return 0;
	}

	dfloor[0] = u;
	dfloor[1] = -d;


	queue<int> q;
	visited[s] = 1;
	q.push(s);
	while (q.size()) {
		int floor = q.front(); q.pop();
		for (int i = 0; i < 2; i++) {
			int nfloor = floor + dfloor[i];
			
			if (nfloor < 1 || nfloor > f) continue;
			if (visited[nfloor]) continue;
			visited[nfloor] = visited[floor] + 1;
			if (nfloor == g) {
				chk = 1; break;
			}
			q.push(nfloor);
			
		}
	}

	
	if (!chk) cout << "use the stairs";
	else cout << visited[g] - 1 << '\n';

	return 0;
}

