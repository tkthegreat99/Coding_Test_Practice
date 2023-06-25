#include<iostream>
using namespace std;
int main(void) {
	int answer = 0;
	char a[8][9];	
	
	for (int i = 0; i < 8; i++)
		cin >> a[i];

	
	for (int i = 0; i < 8; i++) {
		for (int j = i % 2; j < 8; j += 2) {
			if (a[i][j] == 'F')
				answer++;
		}
	}
	
	cout << answer << '\n';
}