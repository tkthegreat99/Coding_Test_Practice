#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b);
int mok(int num);

bool cmp(int a, int b)
{
    if(mok(a) == mok(b))
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    return mok(a) > mok(b);
}

int mok(int num)
{
    if(num < 10) return num;
    else if(10<= num && num < 100) return num / 10;
    else if (100 <= num && num < 1000) return num / 100;
    else return 1;
}


string solution(vector<int> numbers) {
    string answer = "";
    int chk = 0;
    for(int num : numbers)
    {
        if(num != 0) chk = 1;
    }
    
    if(!chk) return "0";
    
    sort(numbers.begin(), numbers.end(), cmp);
    // 맨 앞자리가 큰 걸로 정렬
    
    for(int num : numbers)
    {
        answer += to_string(num);
    }
     
    
    
    
    return answer;
}