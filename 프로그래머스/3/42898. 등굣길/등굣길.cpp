#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[101][101];
vector<vector<int>> puddle;

bool CanGo(int x, int y)
{
    for(int i = 0; i < puddle.size(); i++)
    {
        if(puddle[i][0] == x && puddle[i][1] == y)
        {
            return false;
        }
    }
    return true;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    puddle = puddles;
    
    if(m == 1 && n == 1) return 1;
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1) continue;
            
            if(i == 1)
            {
                if(CanGo(1, j-1))
                {
                    dp[1][j] = dp[1][j-1]; 
                    
                }
            }
            else if (j == 1)
            {
                if(CanGo(i-1, 1))
                {
                    dp[i][1] = dp[i-1][1];
                    
                }
            }
            else
            {
                bool bup = CanGo(i, j-1);
                bool bleft = CanGo(i-1, j);
                if(bup && bleft) dp[i][j] = dp[i][j-1] + dp[i-1][j];
                else if(bup && !bleft) dp[i][j] = dp[i][j-1];
                else if(!bup && bleft) dp[i][j] = dp[i-1][j];
                
                dp[i][j] %= 1000000007;
            }
        }
    }
    
    answer = dp[m][n] % 1000000007;
    
    
    
    
    
    return answer;
}