#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day;//걸리는 일 수에 대한 배열
    for(int i = 0; i < progresses.size(); i++)
    {
        int d = ((100 - progresses[i]) % speeds[i]) == 0 ? ((100 - progresses[i]) / speeds[i]) : ((100 - progresses[i]) / speeds[i]) + 1;
        day.push_back(d);
    }
    
    int cnt = 0;
    int tmpday = day[0];
    
    for(int i = 0 ; i < day.size(); i++)
    {
        if(day[i] > tmpday) // tmpday보다 클 경우
        {
            answer.push_back(cnt);
            tmpday = day[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
        
        if(i == day.size() - 1) answer.push_back(cnt);
        
        
    }
    
    return answer;
}