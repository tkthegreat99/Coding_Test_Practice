#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int a[51][51]; //a[준 사람][받은 사람] = 개수 
map<string, int> NameIndex;
int jisu[51][3];
int ret[51];

vector<string> split(string str)
{
    vector<string> ret;
    string tmp;
    istringstream ss(str);
    while(ss >> tmp){
        ret.push_back(tmp);
    }
    return ret;
}


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i = 0 ; i < friends.size(); i++) NameIndex[friends[i]] = i;
    for(int i = 0 ; i < gifts.size(); i++)
    {
        vector<string> tmp = split(gifts[i]);
        string giver = tmp[0];
        string receiver = tmp[1];
        a[NameIndex[giver]][NameIndex[receiver]]++;
    }
    
    for(int i = 0 ; i < friends.size(); i++)
    {
        int give = 0;
        int get = 0;
        for(int j = 0 ; j < friends.size(); j++)
        {
            give += a[i][j]; //0 2 0 -> 2
            get += a[j][i];  //3, 1, 1 
        }
        jisu[i][0] = give;
        jisu[i][1] = get;
        jisu[i][2] = give - get;
    }
    int mx = -1;
    cout << "주고 받은 거 \n";
    
    
    
    for(int i = 0 ; i < friends.size(); i++)
    {
        for(int j = i+1 ; j < friends.size(); j++){
            
            if(a[i][j] == a[j][i]) // 주고받은 수가 같음 둘다 0 으로 주고받지 않은 것도 포함됨
            {
                if(jisu[i][2] == jisu[j][2]) continue;
                else
                {
                    if(jisu[i][2] > jisu[j][2])
                    {
                        ret[i]++;
                    }
                    else ret[j]++;
                }                
            }
            else  // 주고받았다면
            {
                if(a[i][j] > a[j][i]) ret[i]++;
                else if (a[i][j] < a[j][i]) ret[j]++;
            }
        }
        
    }
    
    for(int i = 0 ; i < friends.size(); i++)
    {
        cout << ret[i] << " ";
    }
    
    for(int i = 0 ; i< friends.size(); i++)
    {
        mx = max(mx, ret[i]);
    }
    
    answer = mx;
    
    return answer;
}
//frodo 한테 준 애들 muzi, ryan
// 


/*
gits를 돌면서 준 사람과 받은 사람을 map에 기록. 두 map을 기준으로 선물지수 map도 새성해놓음.
다음 달에 선물 받을 수를 계산해보고, max 탐색.

*/

