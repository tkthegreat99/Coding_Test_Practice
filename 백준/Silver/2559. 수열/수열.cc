	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <string>
	#include <queue>

	using namespace std;


	int psum[100001];


	int main() {

		ios::sync_with_stdio(false);
		cin.tie(nullptr); cout.tie(nullptr);

		int n;
		int k;	
		cin >> n >> k;
		int tmp;

		
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			psum[i] = psum[i - 1] + tmp; // 구간합
		}
		int ret = -999999;
		for (int i = k; i <= n; i++) {
			ret = max(ret, psum[i] - psum[i - k]);
		}
		cout << ret << '\n';
	
		return 0;
	}

	

