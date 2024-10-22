#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mx = -1;
int curtired;

bool CanGo(int mintired)
{
    if(curtired < mintired) return false;
    return true;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int cnt = 0;
    curtired = k;
    vector<int> sunseo;
    for(int i = 0 ; i< dungeons.size(); i++) sunseo.push_back(i);
    
    do{
        cnt = 0;
        curtired = k;
        
        for(int i = 0 ; i < sunseo.size(); i++)
        {
            //cout << "현재 피로도 : " << curtired << '\n';
            int nextmin = dungeons[sunseo[i]][0];
            int nextused = dungeons[sunseo[i]][1];
            //cout << "최소 피로도 : " << nextmin << '\n';
            //cout << "사용될 피로도 : " << nextused << '\n';
            if(CanGo(nextmin) == true)
            {
                cnt++;
                curtired -= nextused;
                //cout << "릴레이 cnt : " <<  cnt <<'\n';
            }
            
            mx = max(mx, cnt);
        }
        
        
        
    }while(next_permutation(sunseo.begin(), sunseo.end()));
    
    
    answer = mx;
    return answer;
}

// next_permutatioon 으로 모든 가능한 순서를 세워본다음
// 돌면서 최대 던전수를 탐색 탐색 불가능한 순간 다음 순서로 넘어가기.

// 다음 던전에 들어갈 수 있는지 확인해주는 함수
// 현재 피로도 관리하는 함수