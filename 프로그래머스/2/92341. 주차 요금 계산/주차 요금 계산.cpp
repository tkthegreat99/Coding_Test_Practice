#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
//map 에 차량번호 - 입차 시간 을 저장해놓고
// records를 탐색하면서 out인것을 찾고, out에 해당되는 차량번호에 대해 누적 주차 시간을 계산
// 만약 out이 없다면, 23:59 까지 주차한 것으로 판단.
// 누적 주차시간이 기본 시간보다 작으면 기본요금, 아니면 분당 단위 시간을 부여.


using namespace std;
vector<int> answer;
vector<int> fee;
map<string, int> InTime; // 입차시간을 기록, 새로운 입차시간을 계속 업데이트함.
map<string, bool> IsInParkingLot; // 현재 차가 들어와있는지를 기록.
map<string, int> UsedTime; // 차 별 누적 시간을 기록.


int HourToMin(string str)
{
    int time = ((str[0] - '0') * 10 + str[1] - '0')*60 + (str[3] - '0') * 10 + str[4] - '0';
    return time;
}

void CalTime()
{
    int defaulttime = fee[0];
    int defaultfee = fee[1];
    int unittime = fee[2];
    int unitfee = fee[3];
    map<string, int>::iterator iter;
    for(iter = UsedTime.begin(); iter != UsedTime.end(); ++iter)
    {
        //cout << iter->first << " : " << iter->second << '\n';
        if(iter->second <= defaulttime)
        {
            answer.push_back(defaultfee);
        }
        else
        {
            if((iter->second - defaulttime) % unittime == 0)
            {
                answer.push_back(defaultfee + (iter->second - defaulttime) / unittime * unitfee);
            }
            else
            {
                answer.push_back(defaultfee + (((iter->second - defaulttime) / unittime) + 1) * unitfee);
            }
            
        }
    }
}


vector<int> solution(vector<int> fees, vector<string> records) {
    
    fee = fees;
    for(int i = 0 ; i < records.size(); i++)
    {
        string car = records[i].substr(6, 4);
        string time = records[i].substr(0, 5);
        if(records[i][11] == 'I')
        {
            InTime[car] = HourToMin(time);
            IsInParkingLot[car] = true;
        }
        else
        {
            UsedTime[car] += HourToMin(time) - InTime[car]; //누적 시간 더하기
            IsInParkingLot[car] = false;
        }
    }
    
    map<string, bool>::iterator iter;
    for(iter = IsInParkingLot.begin(); iter != IsInParkingLot.end(); ++iter)
    {
        if(iter->second == true)
        {
            UsedTime[iter->first] += HourToMin("23:59") - InTime[iter->first];
        }
    }
    
    CalTime();
    
    return answer;
}