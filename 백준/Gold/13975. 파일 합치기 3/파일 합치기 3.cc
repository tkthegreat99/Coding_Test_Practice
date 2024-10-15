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

int T, k, tmp;


signed main()
{
	fastio;
	
	cin >> T;

	while (T--)
	{
		int testdata = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> tmp;
			pq.push(tmp);
		}

		
		while (k >= 2)
		{
			
			int tmpsum = 0;
			for (int i = 0; i < 2; i++)
			{
				tmpsum += pq.top();
				pq.pop();
			}
			pq.push(tmpsum);
			testdata += tmpsum;
			k--;
		}
		cout << testdata << '\n';
	}
	



}