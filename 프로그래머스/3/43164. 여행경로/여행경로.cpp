#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
int check[10001];
vector<string> answer;
bool bIsAnswer = false;

void dfs(string start, int ticketCnt)
{
    answer.push_back(start);
    if(ticketCnt == ticket.size())
    {
        bIsAnswer = true;
    }
    
    for(int i = 0 ; i < ticket.size(); i++)
    {
        if(check[i]) continue;
        if(ticket[i][0] == start)
        {
            check[i] = 1;
            dfs(ticket[i][1], ticketCnt+1);
            
            if(!bIsAnswer)
            {
                answer.pop_back();
                check[i] = false;
            }
            
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
   sort(tickets.begin(), tickets.end());
    
    ticket = tickets;
    dfs("ICN", 0);
    return answer;
}

// 1. 맨 앞이 Cur 인 애들을 찾음.
// 2. 찾은 애들을 임시 string 배열에 넣고 sort.
// 3. sort된 배열에서 앞에서부터 방문하지 않은 곳에 방문, 방문 체크
// 4. 반복