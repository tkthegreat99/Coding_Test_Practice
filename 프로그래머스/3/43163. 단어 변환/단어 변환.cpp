#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int answer = 999999;

int IsOneWordDifferent(string a, string b);

int CheckTargetIsInWords(string target, vector<string> words)
{
    int chk = 0;
    for(string str : words)
    {
        if(str == target) chk = 1;
    }
    if(chk) return 1;
    else return 0;
}



int IsOneWordDifferent(string a, string b)
{
    int count = 0;
    for(int i = 0 ; i < a.size(); i++)
    {
        if(a[i] != b[i]) count++;
    }
    if(count == 1) return 1;
    else return 0;
}


void dfs(vector<pair<string, int>> visit, string cur, string target, int depth)
{
    if(cur == target) 
    {
        answer = min(answer, depth);
        return;
    }
    
    
    
    for(int i = 0 ; i < visit.size(); i++) // visit 배열 탑색해서
    {
        if(IsOneWordDifferent(visit[i].first, cur)) //하나 차이나는 애를 구함
        {
            if(visit[i].second == 0)
            {
                visit[i].second = 1;
                dfs(visit, visit[i].first, target, depth+1);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<pair<string, int>> visited;
    
    int bIsTargetIsInWords = CheckTargetIsInWords(target, words);
    if(!bIsTargetIsInWords) 
    {
        return 0;
    }
    
    for(string str : words)
    {
        visited.push_back({str, 0});
    }
    
    dfs(visited, begin, target, 0);
    
    return answer;
}



//words 배열에서 하나 차이나는 애들을 찾음.
// 하나 차이나고 !visited 라면 들어감. depth 늘림.
// 만약 target이 되면 종료. depth를 보고 작은 값을 선택