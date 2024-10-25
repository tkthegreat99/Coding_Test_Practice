#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#define long long int
using namespace std;


int robotn;
vector<vector<pair<int, int>>> locformin(101); // 헷갈리니까 0 인덱스는 비워놓고 1~n까지의 로봇 경로를 저장하자.
vector<vector<int>> point; //포인트들 좌표 저장해놓은 것.
int a[101][101][20000];

//로봇 번호와 현재 포인트, 목적 포인트를 입력하면 목적에 갈 때까지의 경로를 추가해주자.
void Addroute(int curRobot,int curpoint, int targetpoint)
{
    pair<int, int> curCor = make_pair(point[curpoint - 1][0], point[curpoint - 1][1]);
    pair<int, int> tarCor = make_pair(point[targetpoint - 1][0], point[targetpoint - 1][1]);
    
    
    
    int disty = tarCor.first - curCor.first;
    int distx = tarCor.second - curCor.second;
    
    if(disty == 0 && distx == 0) return;
    
    // 만약 1 - >3 이라 할 떄
    // (3, 2) -> (4, 7) 이니까 disty = 1, distx = 5
    
    while(disty != 0)
    {
        if(disty > 0) 
        {
            disty--;
            curCor.first++;
        }
        else 
        {
            disty++;
            curCor.first--;
        }
        locformin[curRobot].push_back({curCor});
        //cout << "A: " << curCor.first << " " << curCor.second << '\n';
    }
    // (4, 2) 되고
    while(distx != 0)
    {
        if(distx > 0) 
        {
            distx--;
            curCor.second++;
        }
        else 
        {
            distx++;
            curCor.second--;
        }
        locformin[curRobot].push_back({curCor});
        //cout << "B: " << curCor.first << " " << curCor.second << '\n';
    }
    // (4, 3) -> (4, 4) -> (4, 5)->(4, 6) -> (4, 7) 될것.
    
    // 완료?
    //locformin[curRobot].push_back({curCor});
}


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    
    // 1번 포인트는 (3, 2) 2번 포인트는 (6, 4)...이렇게 있고
    // 1번 로봇은 4번 포인트 -> 2번 포인트 이렇게 갈거임.
    int answer;
    
    point = points;
    robotn = routes.size();
    
    for(int i = 0 ; i < robotn; i++)
    {
        int curloc = routes[i][0];
        locformin[i + 1].push_back(make_pair(point[curloc - 1][0], point[curloc-1][1]));
        for(int j = 0 ; j < routes[i].size() ; j++)
        {
            Addroute(i + 1, curloc, routes[i][j]); // 로봇, 현재위치, 목적지
            curloc = routes[i][j]; // 현재 위치를 목적지로 변경해줌.
        }
    }
    
    
    int cnt = 0;
    
    
    //로봇 별로 로봇의 0, 1, 2.... 계속 넣어줘야댐
    for(int i = 1; i <= robotn; i++)
    {
        for(int j = 0 ; j < locformin[i].size(); j++)
        {
            a[locformin[i][j].first][locformin[i][j].second][j]++;
            if(a[locformin[i][j].first][locformin[i][j].second][j] == 2)
            {
               //cout << locformin[i][j].first << " "  << locformin[i][j].second << "에서" << j << "초에" << '\n';
                cnt++;
            }
        }
    }
    
    
    // 반례-> (2, 3)에 3초에 들어와서 a(2, 3) = 3, check(2, 3) = 1로 되어있는데 (2, 3)에 5초에 다른 두개가 들어올려고함./
    //근데 이미 check되어있어서 못들어옴.
    answer = cnt;
    
    
    /*
    for(int i = 1; i <= robotn; i++)
    {
        cout << i << "번 로봇 : ";
        for(pair<int, int> x : locformin[i])
        {
            cout << "("<< x.first << " , " << x.second <<")"<< "-> ";
        }
        cout << '\n';
    }
    */
    
    
    
    
    return answer;
}

/*
1. 초 당 로봇의 이동 좌표를 기록해놓자. 1번 -> (1, 2) , ...이런식으루
2. 그런다음에 초 별로 겹치는 부분을 카운트

*/