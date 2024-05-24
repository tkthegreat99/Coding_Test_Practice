#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> tmp;
    
    for(int i = 0 ; i < commands.size(); i++){
        for(int j = commands[i][0] - 1 ; j < commands[i][1]; j++){
            tmp.push_back(array[j]);
        }
        /*
        cout << "tmp : ";
        for(int x : tmp) cout << x  << " ";
        */
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
        tmp.clear();
    }
    return answer;
}