#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[501][501];


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[1][0] = triangle[0][0];
    
    for(int i = 2; i <= triangle.size(); i++)
    {
        dp[i][0] = dp[i-1][0] + triangle[i-1][0];
         //cout << "dp["<< i <<"]" << "[" << "0" << "] = " << dp[i][0] << '\n';
        dp[i][i] = dp[i-1][i-1] + triangle[i-1][i-1];
        //cout << "dp["<< i <<"]" << "[" << i << "] = " << dp[i][i] << '\n';
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i-1][j];
           // cout << "dp["<< i <<"]" << "[" << j << "] = " << dp[i][j] << '\n';
        }
    }
    
    for(int i = 0; i < triangle.size(); i++)
    {
        //cout << dp[triangle.size()][i] << " ";
        answer = max(answer, dp[triangle.size()][i]);
    }
    
    
    
    
    return answer;
}