#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<string> v;
string alpha[5] = {"A", "E", "I", "O", "U"};
void dfs(string str, int len)
{
    if(str.size() == len + 1)
    {
        return;
    }
    v.push_back(str);
    dfs(str+"A", len);
    dfs(str+"E", len);
    dfs(str+"I", len);
    dfs(str+"O", len);
    dfs(str+"U", len);
}


int solution(string word) {
    int answer = 0;
    
    dfs("", 5);
    
    sort(v.begin(), v.end());
   
    
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == word) return i;
    }
    
    
    
    
    
    return answer;
}