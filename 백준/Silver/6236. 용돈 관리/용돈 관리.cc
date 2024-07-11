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


int n, m;
int a[100001];
int tot;
int ret = 1e9;
int mx = -1e9;


int check(int mid) {


	//mid = 인출금액
	// a[i] = 그 날 쓸 금액
	// mid < a[i] -> 돈이 부족해서 더 많이 뽑아야댐
	int tmp = 0;
	int currentmoney = 0;

	for (int i = 0; i < n; i++) {

		//cout << "currentmoney : " << currentmoney << '\n';
		//cout << "그 날 쓸 금액 : " << a[i] << '\n';
		if (currentmoney < a[i]) {
			tmp++;
			//cout << "돈 꺼낸 횟수 : " << tmp << '\n';
			currentmoney = mid;
		}
		currentmoney -= a[i];

	}

	if (tmp <= m) return 1;
	else return 0;
}




int main() {

	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tot += a[i];
		mx = max(mx, a[i]);
	}

	int l = mx;
	int r = tot;
	int mid = (l + r) / 2;

	while (l <= r) {

		
		mid = (l + r) / 2;

		//cout << "mid : " << mid << '\n';

		int flag = check(mid);

		if (flag) {
			r = mid - 1;
			ret = min(ret, mid);
		}
		else l = mid + 1;
	}

	cout << ret;
}