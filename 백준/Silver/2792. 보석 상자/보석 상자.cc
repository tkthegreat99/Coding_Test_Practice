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
int k;
int a[300001];
int ret = 1e9;


int main() {

	fastio;

	cin >> n >> m;

	int e = 0, s = 1, mid;
	int tmp;


	for (int i = 0; i < m; i++) {
		cin >> k;
		a[i] = k;
		e = max(e, k);
	}

	//a배열에는 색깔별 개수 가 들어있구요
	//e는 색깔 개수 최댓값이에요

	while (s <= e) {


		tmp = 0;
		mid = (s + e) / 2;
		
		for (int i = 0; i < m; i++) {
			
			if (a[i] % mid) tmp += a[i] / mid + 1;
			else tmp += a[i] / mid;
		}

		if (tmp > n) s = mid + 1;
		else {
			e = mid - 1;
			ret = min(ret, mid);
		}
	}


	cout << ret;




}