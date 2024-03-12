#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
int num, turn;
map<string, int> mp;


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int chk = 0;
    for(int i = 0 ; i < words.size(); i++){

        if(i >= 1){
            if(words[i-1][words[i-1].size()-1] != words[i][0]){
                mp[words[i]]++;
            }
        }
        mp[words[i]]++;
        if(mp[words[i]] > 1){
            chk = 1;
            turn = (i / n) + 1;
            num = (i % n) + 1;
            break;
        }
    }
    if(chk == 0){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(num);
    answer.push_back(turn);
    return answer;
}