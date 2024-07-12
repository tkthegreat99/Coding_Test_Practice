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


/*

길이가 일정하지 않은 파 여러 개 구매
파닭에 같은 양의 파를 넣는다.
파를 최대한 많이 넣으려고 한다.

파 길이의 최댓값을 구해야함.


*/


int s, c;
int length;
int remain;
int MinLength = -1e9;
vector<int> v;
int ret = -1e9;

int check(int mid) {
	int cnt = 0;

	
	for (int i = 0; i < s; i++) {
		cnt += (v[i] / mid);
		//cout << "mid : " << mid << "파 길이 " << v[i] << " 나눠진 개수" << v[i] / mid << '\n';
	}
	if (cnt >= c) {
		//cout << "치킨 개수랑 파 개수 같음\n";
		return 1;
		
	}
	//1의 의미 : 잘라진 파의 개수가 파닭과 같다.
	// -> 파 크기를 더 크개 해보자
	else return 0;
	
}




signed main() {

	fastio;
	

	cin >> s >> c;

	for (int i = 0; i < s; i++) {
		cin >> length;
		v.push_back(length);
		MinLength = max(MinLength, length);
		remain += length;
	}

	int l = 1;
	int r = MinLength;
	int mid = (l + r) / 2;
	int cnt = 0;


	while (l <= r) {

		mid = (l + r) / 2;

		int flag = check(mid);

		if (flag) {
			l = mid + 1;
			ret = max(mid, ret);
		}

		else {
			r = mid - 1;
		}
	}

	//cout << ret << '\n';

	cout << remain - (ret * c);


	/*
	100 40 40   20 
	60 40   20 
	40 40 0

	
	*/

	

}