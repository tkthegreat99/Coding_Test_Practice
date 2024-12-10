#include <iostream>
#include <vector>
#include <unordered_map>
#define int long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int T;
int n, m;
vector<int> A;
vector<int> B;
unordered_map<int, int> psum_A;

void input() {
    cin >> T;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> m;
    B.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
}

void calculateSubarrays(vector<int>& arr, unordered_map<int, int>& psum, int len) {
    for (int start = 0; start < len; ++start) {
        int sum = 0;
        for (int end = start; end < len; ++end) {
            sum += arr[end];
            psum[sum]++;
        }
    }
}

int countPairsWithSumT() {
    int count = 0;
    // Process A to store subarray sums
    calculateSubarrays(A, psum_A, n);
    
    // Process B and count pairs directly
    for (int start = 0; start < m; ++start) {
        int sum = 0;
        for (int end = start; end < m; ++end) {
            sum += B[end];
            if (psum_A.count(T - sum)) {
                count += psum_A[T - sum];
            }
        }
    }

    return count;
}

signed main() {
    fastio;
    input();
    cout << countPairsWithSumT() << '\n';
    return 0;
}
