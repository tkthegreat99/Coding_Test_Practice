#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> TypeOfCloth;


int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int tmp = 1;
    
    for(int i = 0 ; i < clothes.size() ; i++)
    {
        TypeOfCloth[clothes[i][1]]++;
    }
    if(TypeOfCloth.size() == 1){
        for(pair<string, int> x : TypeOfCloth)
        {
            answer = x.second;
        }
    }
    else
    {
        for(pair<string, int> x : TypeOfCloth)
        {
            tmp *= (x.second+1);
        }
        tmp--;
        answer = tmp;
    }
    
    
    
    
    return answer;
}