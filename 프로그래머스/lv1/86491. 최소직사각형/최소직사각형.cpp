#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int bigger, max_w = 0;
    int lesser, max_h = 0;
    
    for(int i = 0 ; i < sizes.size(); i++)
    {
        bigger = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        lesser = bigger == sizes[i][0] ? sizes[i][1] : sizes[i][0];
        if (bigger > max_w) max_w = bigger;
        if (lesser > max_h) max_h = lesser;
    }
    
    
    return max_w * max_h;
}