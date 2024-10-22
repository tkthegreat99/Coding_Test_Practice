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


signed main()
{
	fastio;
	
	cin >> n;
	vector<int> v(n), dp(n, 1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);
	cout << *max_element(dp.begin(), dp.end()) << '\n';


	return 0;
}