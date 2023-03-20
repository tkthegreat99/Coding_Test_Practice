#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool cmp(int i, int j) {
	return i < j;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n; // 선물 상자 수
	int m; // 애들 수

	priority_queue<int> gift; // 선물 상자 우선순위 큐
	vector<int> children; //애들 원하는 수

	cin >> n >> m;

	int tmp;

	//선물 상자 수만큼 반복되고 queue에 삽입
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		gift.push(tmp);
	}

	//애들 수 만큼 vector<int>에 삽입
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		children.push_back(tmp);
	}

	int chk = 0;
	//애들 수 만큼만 반복(vector<int> 탐색)
	for (int i = 0; i < m; i++) {
		tmp = gift.top() - children[i];
		if (tmp < 0) {
			cout << 0 << '\n';
			chk = 1;
			return 0;
		}
		else {
			gift.pop();
			gift.push(tmp);
		}
	}
	
	if (chk == 0) {
		cout << 1 << '\n';
	}




	

}

	

