#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int x : scoville) pq.push(x);
    while(pq.size() && pq.top() < K)
    {
        if(pq.size() == 1) return -1;
    
        if(pq.size() >= 2)
        {
            int tmp1 = pq.top(); pq.pop();
            int tmp2 = pq.top(); pq.pop();
            pq.push(tmp1 + tmp2 * 2);
        }
        
        answer++;
    }
    
    return answer;
}