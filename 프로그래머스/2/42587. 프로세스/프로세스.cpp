#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int MaxElement(queue<pair<int, int>> q)
{
    int mx = 0;
    while(!q.empty())
    {
        int tmp = q.front().second;
        mx = max(mx, tmp);
        q.pop();
    }
    return mx;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int n = priorities.size();
    queue<pair<int, int>> q;
    //프로그램, 우선순위
    for(int i = 0 ;i < n; i++)
    {
        q.push({i, priorities[i]});
    }
    
    int RunProcess = -1;
    
    while(1)
    {
        if(q.empty()) break;
        
        int CurProgram = q.front().first;
        int CurPriority = q.front().second;
        if(CurPriority < MaxElement(q))
        {
            q.pop();
            q.push({CurProgram, CurPriority});
        }
        else
        {
            RunProcess = CurProgram;
            q.pop();
            answer++;
        }
        if(RunProcess == location) return answer;
        
    }
    
    
    
    
    
    
    
    
    return answer;
}

