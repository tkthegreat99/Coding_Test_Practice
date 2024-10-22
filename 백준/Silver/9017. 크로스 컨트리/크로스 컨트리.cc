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

int T;

signed main()
{
	fastio;
	int n;
	int tmp;

	cin >> T;
	
	while (T--)
	{
		vector<int> v;
		map<int, int> m;
		vector<pair<int, int>> res;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
			m[tmp]++;
		}
		
		vector<int> realv;
		for (int i = 0; i < n; i++)
		{
			if (m[v[i]] >= 6) realv.push_back(v[i]);
		}

		int team_num = m.size();

			
		vector<vector<int>> order(team_num + 1);

		
		for (int i = 0; i < realv.size(); i++)
		{
			order[realv[i]].push_back(i + 1); // 각 팀별로 order 넣어줌
		}
		/// team 1 : 1, 5, 
		/// team 3 : 2, 3, ...
		/// 
		
		
		
		for(int i = 0; i < order.size(); i++)
		{
			if (order[i].size() < 6) continue;
			tmp = 0;
			for (int j = 0; j < 4; j++)
			{
				tmp += order[i][j];
			}
			res.push_back({ tmp, i });
			//cout << tmp << ", " << i << '\n';
		}
		
		
		sort(res.begin(), res.end());

		

		if (res[0].first != res[1].first)
		{

			cout << res[0].second << '\n';
		}
		else
		{
			int score = res[0].first;
			int mn = 9999;
			int mnt = -1;
			for (int i = 0; i < res.size(); i++)
			{
				if (score != res[i].first) break;
				mn = min(mn, order[res[i].second][4]);
				if (mn == order[res[i].second][4]) mnt = res[i].second;
			}
			cout << mnt << '\n';
		}
		
		
	}

}

/*

우선 달리기 배열을 벡터 벡터로 받음
1팀 : 1, 5, ....
2팀 : 
3팀 : 

앞의 네 개 팀 합 더하고
같으면 다섯번째 인덱스 비교하기

*/

///