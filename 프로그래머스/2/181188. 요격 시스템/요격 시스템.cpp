#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> p, vector<int> q){
    if(p[0] == q[0]) return p[1] < q[1];
    return p[1] < q[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    
    int cur = targets[0][1];
    
    for(int i = 1; i < targets.size(); i++){
        if(targets[i][0] >= cur){
            answer++;
            cur = targets[i][1];
        }
    }
    
    return answer;
}