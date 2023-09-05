#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> map_participant;
map<string, int> map_completion;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    string tmp = "";
    
    for(int i = 0 ; i < participant.size(); i++)
    {
        map_participant[participant[i]]++;
        map_completion[participant[i]] = 0;
    }
    
    for(int i = 0 ; i < completion.size(); i++)
    {
        map_completion[completion[i]]++;
    }    
    
    for(pair<string, int> x : map_participant)
    {
        if(map_participant[x.first] != map_completion[x.first])
            if (answer == "") answer += x.first;
    }
    
    return answer;
}