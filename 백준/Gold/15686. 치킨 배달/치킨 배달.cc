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

int a[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

signed main()
{
	fastio;
	int n, m;
	// m은 고르는 치킨 집 개수.

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) home.push_back({ i, j });
			if (a[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	//치킨집 총 개수
	int c_num = chicken.size();

	//이 중에 m개 뽑는다고 했을 때.. ex) 0 0 0 1 1 5개중 2개
	vector<int> v;
	for (int i = 0; i < c_num - m; i++) v.push_back(0);
	for (int i = 0; i < m; i++) v.push_back(1);
	// m개의 1을 해놓고 모든 인덱스를 탐구하게 할거임..

	int dist;
	int ret = 0;
	int mn = 1e9;

	do {
		ret = 0;
		vector<pair<int, int>> selected_c; // 뽑힌 치킨집 애들
		for (int i = 0; i < v.size(); i++)
		{
			//i 가 곧 인덱스니까 치킨집 모음에서 인덱스 칠해진 애들 selected에 넣음
			if (v[i] == 1) selected_c.push_back(chicken[i]);
		}

		//for (pair<int, int> k : selected_c) cout << k.first << " " << k.second << '\n';

		//집별로 치킨 거리를 계산
		
		for (pair<int, int> _home : home)
		{
			int mndist = 1e9;
			//cout << "home : " << _home.first << " , " << _home.second << '\n';
			for (pair<int, int> _chick : selected_c)
			{
				//집에서 각 치킨집과의 거리
				dist = abs(_home.first - _chick.first) + abs(_home.second - _chick.second);
				//cout << "dist : " << dist << '\n';
				mndist = min(mndist, dist);
			}
			//mndist는 해당 집의 치킨 거리, 모든 집의 치킨 거리를 더해야 하니까
			ret += mndist;
			//cout << "ret : " << ret << " , mndist : " << mndist << '\n';
		}
		mn = min(ret, mn);


	} while (next_permutation(v.begin(), v.end()));
	
	cout << mn << '\n';
}

/*
1. 치킨집 배열과 집 배열을 만듬. (좌표를 저장)
2. 치킨집 배열에서 m개의 치킨집을 고르고, 각 집에서 치킨 거리를 구한다.
3. m개의 치킨 집 골랐을 때의 치킨 거리 합을 고르고 min인지 확인.


*/