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
	string tmp;
	int tmpnum;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		
		reverse(tmp.begin(), tmp.end());
		
		tmpnum = stol(tmp);
		pq.push(tmpnum);
	}

	while (pq.size())
	{
		if (pq.top())
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
	}


}