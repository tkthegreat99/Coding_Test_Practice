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
#include <deque>
#include <sstream>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


int n;
int mn = 1e9;
int finish = 0;
int dp[61][61][61];

int a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};


struct A {
	int a;
	int b;
	int c;
};

signed main()
{
	fastio;
	
	cin >> n;
	int tmp;
	vector<int> scv;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;;
		scv.push_back(tmp);
	}
	for (int i = 0; i < 3 - n; i++) scv.push_back(0);



	queue<A> q;
	q.push({ scv[0], scv[1], scv[2] });
	while (q.size())
	{
		int scv1 = q.front().a;
		int scv2 = q.front().b;
		int scv3 = q.front().c;
		//cout << scv1 << ", " << scv2 << ", " << scv3 << '\n';
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int next1 = scv1 - a[i][0] <= 0 ? 0 : scv1 - a[i][0];
			int next2 = scv2 - a[i][1] <= 0 ? 0 : scv2 - a[i][1];
			int next3 = scv3 - a[i][2] <= 0 ? 0 : scv3 - a[i][2];
			if (dp[next1][next2][next3] != 0) continue;
			dp[next1][next2][next3] = dp[scv1][scv2][scv3] + 1;
			if (next1 == 0 && next2 == 0 && next3 == 0) break;
			q.push({ next1, next2, next3 });
		}
	}

	cout << dp[0][0][0] << '\n';
}

/*




*/