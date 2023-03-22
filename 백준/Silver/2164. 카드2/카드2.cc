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


	queue<int> q;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}


	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();


	

}

	

