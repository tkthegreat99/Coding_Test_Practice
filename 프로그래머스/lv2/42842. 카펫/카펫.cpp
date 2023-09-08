#include <string>
#include <vector>

using namespace std;

int tmp_width, tmp_height;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int halfbrown = brown / 2;
    int mx_width = halfbrown % 2 == 0 ? halfbrown / 2 : (halfbrown + 1) / 2;
    
    for(int i = 2; i <= mx_width ; i++)
    {
        tmp_width = halfbrown - i + 1;
        tmp_height = i + 1;
        if(tmp_width >= tmp_height && ((tmp_width - 2) * (tmp_height - 2) == yellow))
        {
            answer.push_back(tmp_width);
            answer.push_back(tmp_height);
        }
    }
    return answer;
}