#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long

#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, ATK;
int t, a, h;
int ret = LLONG_MAX;
int CurHP;
int CurATK = ATK;

int Monstercheck(tuple<int, int, int> t) {
	int CurrentmonsterHp = get<2>(t);
	int MonsterAttackPower = get<1>(t);
	
	int TimeMonsterAttackMe = (CurHP % MonsterAttackPower) == 0 ? (CurHP / MonsterAttackPower) : (CurHP / MonsterAttackPower) + 1;
	int TimeIAttackMonster = (CurrentmonsterHp % CurATK) == 0 ? (CurrentmonsterHp / CurATK) : (CurrentmonsterHp / CurATK) + 1;

	if (TimeIAttackMonster <= TimeMonsterAttackMe) {

		CurHP -= (TimeIAttackMonster - 1) * MonsterAttackPower;
		return 1;
	}
	else return 0;
}



signed main() {

	fastio;

	cin >> n >> ATK;

	vector<tuple<int, int, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		v.push_back({ t, a, h });
	}
	int flag;
	int l = 1;
	int r = LLONG_MAX - 1;
	int mid = (l + r) / 2;
	

	while (l <= r) {

		mid = (l + r) / 2;
		CurHP = mid;
		flag = 1;
		CurATK = ATK;

		for (auto i : v) {
			


			if (get<0>(i) == 1) {
				flag = Monstercheck(i);
				if (!flag) break;
			}

			else if (get<0>(i) == 2) {
				CurATK += get<1>(i);
				CurHP += get<2>(i);
				if (CurHP > mid) CurHP = mid;
			}

		}

		if (!flag) l = mid + 1;
		else {
			r = mid - 1;
			ret = min(ret, mid);
		}
	}

	cout << ret;


	
}