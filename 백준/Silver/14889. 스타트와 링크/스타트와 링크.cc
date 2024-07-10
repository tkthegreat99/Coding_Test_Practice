#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;



int n;

int a[21][21];
int tmp1, tmp2;
vector<vector<int>> team;
int flag[21];
int ret = 1e9;

void combi(int start, vector<int> v) {
	if (v.size() == n / 2) {
		team.push_back(v);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}





int main() {

	fastio;
	cin >> n;
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	combi(-1, v);


	//team에는 지금 012, 013, ... 등의 인덱스가 들어가있다. 6을 넣었으면 3 4 5 까지 있음.

	for (vector<int> x : team) {
		
		fill(flag, flag + 21, 0);
		vector<int> newv;
		tmp1 = tmp2 = 0;

	
		for (int y : x) {
			flag[y] = 1;  // 0 1 2 가 1이면 3 4 5가 0 실제론 1, 2, 3팀 
		}

		for (int i = 0; i < n; i++) {
			if (!flag[i]) newv.push_back(i); // 3 4 5가 추가댐  (실제론 4 , 5, 6 팀)
		}

		//지금 vector<int> x는 0 1 2 상태임


		for (int i = 0; i < n / 2; i++) {

			for (int j = i + 1; j < n / 2; j++) {

				tmp1 += a[x[i]][x[j]] + a[x[j]][x[i]];
				tmp2 += a[newv[i]][newv[j]] + a[newv[j]][newv[i]];

			}

		}

		ret = min(abs(tmp1 - tmp2), ret);

	}
	



	cout << ret;
	




}