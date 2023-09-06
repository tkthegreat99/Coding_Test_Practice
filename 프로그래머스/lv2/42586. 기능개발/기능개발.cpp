#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> endDuration;
    int max, cnt = 0;
    
    for(int i = 0 ; i < progresses.size(); i++)
    {
        if( (100 - progresses[i]) % speeds[i] == 0) 
            endDuration.push_back((100 - progresses[i]) / speeds[i]);
        else endDuration.push_back(((100 - progresses[i]) / speeds[i]) + 1);
    }
    max = -1e9;
    for(int i = 0 ; i < endDuration.size(); i++)
    {
        if(endDuration[i] > max)
        {
            max = endDuration[i];
            cnt++;
            m[cnt] = 1;
        }
        else{
            m[cnt]++;
        }
    }
    for(pair<int, int> x : m)
    {
        answer.push_back(x.second);
    }
    
    return answer;
}