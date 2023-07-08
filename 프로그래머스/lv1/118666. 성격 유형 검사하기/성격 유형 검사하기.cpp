#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    m['R'] = 0;
    m['T'] = 0;
    m['C'] = 0;
    m['F'] = 0;
    m['J'] = 0;
    m['M'] = 0;
    m['A'] = 0;
    m['N'] = 0;
    
    for(int i = 0 ; i < choices.size(); i++){
        if(choices[i] == 1) m[survey[i][0]] += 3;
        else if (choices[i] == 2) m[survey[i][0]] += 2;
        else if (choices[i] == 3) m[survey[i][0]] += 1;
        else if (choices[i] == 5) m[survey[i][1]] += 1;
        else if (choices[i] == 6) m[survey[i][1]] += 2;
        else if (choices[i] == 7) m[survey[i][1]] += 3;
    }
    if(m['R'] >= m['T']) answer += "R";  //같을 땐 R이 더 빠름
    else answer += "T";
    
    if(m['C'] >= m['F']) answer += "C";
    else answer += "F";
    
    if(m['J'] >= m['M']) answer += "J";
    else answer += "M";
    
    if(m['A'] >= m['N']) answer += "A";
    else answer += "N"; 
    
    
    
    return answer;
}