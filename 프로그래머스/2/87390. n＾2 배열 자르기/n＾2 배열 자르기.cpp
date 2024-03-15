#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int row1 = left / n, col1 = left % n;
    int row2 = right / n, col2 = right % n;

    if (row1 == row2) {
        for (int i = col1; i <= col2; i++) {
            if (i < row1) answer.emplace_back(row1 + 1);
            else answer.emplace_back(i + 1);
        }
    }
    else {
        for (int i = col1; i < n; i++) {
            if (i < row1) answer.emplace_back(row1 + 1);
            else answer.emplace_back(i + 1);
        }
        for (int i = row1 + 1; i < row2; i++) {
            for (int j = 0; j < n; j++) {
                if (j < i) answer.emplace_back(i + 1);
                else answer.emplace_back(j + 1);
            }
        }
        for (int i = 0; i <= col2; i++) {
            if (i < row2) answer.emplace_back(row2 + 1);
            else answer.emplace_back(i + 1);
        }
    }

    return answer;
}