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


map<int, int> mp;



bool Kinds()
{
	int cnt = 0;
	for (int i = 1; i<= 9; i++)
	{
		if (mp[i] > 0) cnt++;
	}
	if (cnt > 2) return false;
	else return true;
}
	


signed main()
{
	fastio;

	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		mp[i] = 0;
	}

	vector<int> fruit(n);
	queue<int> q;
	for (int i = 0; i < n; i++) cin >> fruit[i];

	
	for (int i = 0; i < n; i++)
	{
		q.push(fruit[i]);
		mp[fruit[i]]++;
		if (!Kinds()) //종류가 2개 초과라면
		{
			int tmp = q.front();
			q.pop();
			mp[tmp]--;
		}
	}
	
	cout << q.size();


	return 0;
}