#include <vector>
#include <map>
using namespace std;

map<int, int> m;
int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    int cnt = 0;
    
    for(int i = 0 ; i < N; i++)
    {
        if(m[nums[i]] == 0){
            m[nums[i]]++;
            cnt++;
        }
    }
    
    if(cnt > N/2) answer = N/2;
    else answer = cnt;
    
    return answer;
}