#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;



int n, tmp, goal, ret;
vector<int> v;
int l, r;


int main(){
	fastio;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> goal;
	int mid = n / 2;

	sort(v.begin(), v.end());

	// 1 3 4 5 7 9 10 11 12





	l = 0;
	r = v.size() - 1;

	while (l < r) {

		///cout << "l: " << l << " r : " << r << '\n';
		//cout << v[l] << ", " << v[r] << '\n';


		if (v[l] + v[r] < goal) l++;
		else if (v[l] + v[r] > goal) r--;


		else if (v[l] + v[r] == goal) {
			ret++;
			l++;
			r--;
		}


		//cout << "new r : " << r << '\n';
	}
	


	cout << ret;

}
