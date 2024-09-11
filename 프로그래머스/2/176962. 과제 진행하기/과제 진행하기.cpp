#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

int time(string str)
{
    return ((str[0] - '0') * 10 + str[1] - '0') * 60 + (str[3] - '0') * 10 + str[4] - '0';
}

int num(string str) {
    int size = str.length();
    int ten = 1;
    int ret = 0;
    for (int i = 0; i < size - 1; i++) ten *= 10;
    for (int i = 0; i < size; i++) {
        ret += ten * (str[i] - '0');
        ten /= 10;
    }
    return ret;
}

bool cmp(vector<string> a, vector<string> b)
{
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) 
{
    vector<string> answer;
sort(plans.begin(), plans.end(), cmp);
stack<pair<string, int>> paused_plans;

int cur_time = time(plans[0][1]);
int next_time = time(plans[1][1]);
int cur_subject = 0;

while (cur_subject < plans.size() || !paused_plans.empty())
{
    if (!paused_plans.empty()) {

        if (cur_subject == plans.size())
        {
            answer.push_back(paused_plans.top().first);
            paused_plans.pop();
            continue;
        }

        if (cur_time < next_time)
        {
            int remain_time = paused_plans.top().second;
            int available_time = next_time - cur_time;

            if (remain_time <= available_time)
            {
                answer.push_back(paused_plans.top().first);
                paused_plans.pop();
                cur_time += remain_time;
            }

            else
            {
                paused_plans.top().second = remain_time - available_time;
                cur_time = next_time;
            }
            continue;
        }
    }

    cur_time = time(plans[cur_subject][1]) + num(plans[cur_subject][2]);
    next_time = cur_subject + 1 >= plans.size() ? 1440 : time(plans[cur_subject + 1][1]);

    if (cur_time > next_time)
    {
        
        paused_plans.push({ plans[cur_subject][0], cur_time - next_time });
        cur_time = next_time;
    }
    else
    {
        
        answer.emplace_back(plans[cur_subject][0]);
    }

    ++cur_subject;

}

  


return answer;
}