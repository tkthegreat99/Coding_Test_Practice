#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int time(string str)
{
    return ((str[0] - '0') * 10 + (str[1] - '0')) * 60 + (str[3] - '0') * 10 + str[4] - '0';
}

string timetostr(int time)
{
    string tmp = "";
    int hour = time / 60;
    if(hour < 10)
    {
        tmp += "0";
        tmp += to_string(hour);
    }
    else tmp += to_string(hour);
    
    tmp += ":";
    int min = time % 60;
    if(min < 10)
    {
        tmp += "0";
        tmp += to_string(min);    
    }
    else tmp += to_string(min);
    return tmp;
}

int prev(int curtime)
{
    if(curtime < 10) curtime = 0;
    else curtime -= 10;
    return curtime;
}

int next(int curtime, int videolen)
{
    if(videolen - curtime < 10)
    {
        curtime = videolen;
    }
    else curtime += 10;
    return curtime;
}

int pass(int curtime, int op_start, int op_end)
{
    if(curtime >= op_start && curtime <= op_end)
    {
        curtime = op_end;
    }
    return curtime;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int opend = time(op_end);
    int opstart = time(op_start);
    int videolen = time(video_len);
    int cur_time = time(pos);
    
    for(int i = 0; i < commands.size(); i++)
    {
        cur_time = pass(cur_time, opstart, opend);
        if(commands[i] == "next")
        {
            cur_time = next(cur_time, videolen);
        
        }
        else cur_time = prev(cur_time);
        cur_time = pass(cur_time, opstart, opend);
        
    }
    
    answer = timetostr(cur_time);
    
    
    return answer;

}

