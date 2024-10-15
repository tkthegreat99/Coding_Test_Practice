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
	int tmp;
	vector<int> v;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		if (max_pq.size() > min_pq.size()) min_pq.push(v[i]);
		else max_pq.push(v[i]);

		if (!max_pq.empty() && !min_pq.empty()) 
		{

			if (max_pq.top() > min_pq.top())
			{
				int a = max_pq.top(); max_pq.pop();
				int b = min_pq.top(); min_pq.pop();

				max_pq.push(b);
				min_pq.push(a);
			}
			
		}
		cout << max_pq.top() << '\n';
	}



}