#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;   
    
    for(int i = 0 ; i < commands.size(); i++)
    {
        vector<int> tmp; //임시 정수 벡터 선언
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
    }
    
    return answer;
}