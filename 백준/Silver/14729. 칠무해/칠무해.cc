#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;



/* 사용 함수 */
void input();
void solve();

/* 사용 변수 */
int n;
double tmp;
priority_queue<double> pq;
vector<double> v;


int main() {
	//fastio;
	input();
	//solve();
	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (pq.size() == 7) {
			pq.push(tmp); pq.pop();
		}
		else pq.push(tmp);
	}
	while (pq.size()) {
		v.push_back(pq.top()); pq.pop();
	} 
	reverse(v.begin(), v.end());
	for (double i : v) printf("%.3lf\n", i);
}


void solve() {
	
}
