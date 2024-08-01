#include <iostream>
#include <algorithm>
#define INF 2000000000

using namespace std;

int n, target;
int arr[100000];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr+n);

  int start = 0, end = 0;
  int answer = INF;
  while (start < n && end < n) {
    int result = arr[end] - arr[start];
    if (result < target) {
      end++;
    }
    else {
      answer = min(answer, result);
      start++;
    }
  }
  cout << answer;
}